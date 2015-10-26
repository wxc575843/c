#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#define PAGESIZE (getpagesize();)

typedef struct __header_t {
    int size;
    int magic;
}header_t;

typedef struct __node_t{
	int size;
	struct __node_t *next;
}node_t;
void *head;

int mem_init(int size_of_region){
	static int call_times=0;
	++call_times;
	if(size_of_region<=0 || call_times>=2){
		m_error=4;
		return -1;
	}
	// open the /dev/zero device
	int fd = open("/dev/zero", O_RDWR);
	// size_of_region (in bytes) needs to be evenly divisible by the page size
	head=mmap(NULL, size_of_region, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	// free_head=mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (head== MAP_FAILED){
		perror("mmap");
		exit(1);
	}
	// close the device (don't worry, mapping should be unaffected)
	close(fd);
	head=(node_t*)head;
	head->size=4096 - sizeof(node_t);
// head->next   = NULL;
	return 0;
}


void * mem_alloc(int size, int style){
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

}






