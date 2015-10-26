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
	// open device
	int fd=open("~/fileio", O_RDWR|O_CREAT,S_IRWXU^S_IXUSR|S_IRWXG^S_IXGRP|S_IRWXO^S_IXOTH);
	if(fd==-1){
		write(STDERR_FILENO,"open\n",5);
		return -1;
	}
	// size_of_region (in bytes) needs to be evenly divisible by the page size
	size_of_region=(size_of_region % PAGESIZE)?(size_of_region/PAGESIZE+1)*PAGESIZE:size_of_region;
	void* ptr=mmap(NULL, size_of_region, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	// free_head=mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (ptr==MAP_FAILED){
		write(STDERR_FILENO,"MAP_FAILED\n",11);
		return -1;
	}
	// close the device (don't worry, mapping should be unaffected)
	close(fd);
	mem_head=(node_t*)ptr;
	free_head=mem_head;
	free_head->size=size_of_region-sizeof(node_t);
	free_head->next=NULL;
	return 0;
}


void * mem_alloc(int size, int style){
	node_t *ptr=free_head;
	switch(style){
		case M_BESTFIT:

			break;
		case M_WORSTFIT:

			break;

		case M_FIRSTFIT:

			break;
	}
}


int mem_free(void * ptr){
	if(ptr==NULL)
		return 0;

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






