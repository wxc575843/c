#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#define PAGESIZE (getpagesize())

typedef struct __header_t {
    int size;
    int magic;
}header_t;

typedef struct __node_t{
	int size;
	struct __node_t *next;
}node_t;

node_t *free_head=NULL;
node_t *mem_head=NULL;

int mem_init(int size_of_region){
	static int call_times=0;
	++call_times;
	if(size_of_region<=0 || call_times>=2){
		m_error=E_BAD_ARGS;
		return -1;
	}
	// size_of_region (in bytes) needs to be evenly divisible by the page size
	size_of_region=(size_of_region % PAGESIZE)?(size_of_region/PAGESIZE+1)*PAGESIZE:size_of_region;
	void* ptr=mmap(NULL, size_of_region, PROT_READ | PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	// free_head=mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (ptr==MAP_FAILED){
		write(STDERR_FILENO,"MAP_FAILED\n",11);
		return -1;
	}
	// close the device (don't worry, mapping should be unaffected)
	mem_head=(node_t*)ptr;
	free_head=mem_head;
	free_head->size=size_of_region-sizeof(node_t);
	free_head->next=NULL;
	return 0;
}


void * mem_alloc(int size, int style){
	node_t *free_list=free_head,*BF=NULL,*WF=NULL;
	header_t *header;
	// 直接前驱
	node_t* free_list_prev=free_head;
	// 加上头部结构和端口对齐
	int final_size=size+sizeof(header_t);
	final_size=(final_size%8)?final_size/8*8+8:final_size;
	switch(style){
		case M_BESTFIT:
			while(free_list!=NULL){
				if(free_list->size>=final_size && (BF==NULL || BF->size>free_list->size))
					BF=free_list;
				else free_list=free_list->next;
			}
			if(BF==free_head){
				free_head+=final_size;
				free_head->size-=final_size;
			}
			break;
		case M_WORSTFIT:

			break;

		case M_FIRSTFIT:
			while(free_list!=NULL){
				if(free_list->size>=final_size){
					if(free_list==free_head){
						free_head+=final_size;
						free_head->size-=final_size;
						free_head->next=(free_head-final_size)->next;
						header=(header_t*)free_head;
						header->size=size;
						header->magic=12345678;
						return (void*)(header+sizeof(header_t));
					}
					else{
						free_list+=final_size;
						free_list->size-=final_size;
						free_list->next=(free_list+final_size)->next;
						free_list_prev->next=free_list;
						header=(header_t*)free_list;
						header->size=size;
						header->magic=12345678;
						return (void*)(header+sizeof(header_t));
					}
				}
				else{
					free_list_prev=free_list;
					free_list=free_list->next;
				}
			}
			if(free_list==NULL)
				m_error=E_NO_SPACE;
			break;
	}
	return NULL;
}


int mem_free(void * ptr){
	if(ptr==NULL)
		return 0;
	// 利用magic作节点判断
	header_t *p=(header_t*)ptr;
	// 用于free_list中作比较
	node_t *q=(node_t*)ptr;
	p-=sizeof(header_t);
	if(p->magic!=12345678)
		return -1;
	// free之后置magic为0
	p->magic=0;
	// 初始化空闲块
	q->next=NULL;
	q->size=p->size+sizeof(header_t);
	node_t* free_list=free_head;
	if(free_list<q){
		free_head=q;
		q->next=free_list;
	}
	else{
		while(free_list!=NULL){
			if(free_list+(free_list->size)-1<=q && (free_list->next==NULL || free_list->next>=q)){
				// 将空闲块插入空闲块管理表中
				q->next=free_list->next;
				free_list->next=q;
				// 尝试合并相邻空闲块
				node_t* after_q=q->next;
				if(free_list+(free_list->size)-1==q && q+(q->size)-1==after_q){
					free_list->size+=q->size+after_q->size;
					free_list->next=after_q->next;
					break;
				}
				else if(free_list+(free_list->size)-1==q){
					free_list->size+=q->size;
					free_list->next=after_q;
					break;
				}
				else if(q+(q->size)-1==after_q){
					q->size+=after_q->size;
					q->next=after_q->next;
					break;
				}
			}
			else
				free_head=free_head->next;
		}
	}
	ptr=NULL;
	return 0;
}
void mem_dump(){
	node_t *ptr=free_head;
	while(ptr!=NULL){
		printf("A free block starts at %p with %d bytes\n",ptr,ptr->size);
		ptr=ptr->next;
	}
}






