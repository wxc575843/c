#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>

#define PAGESIZE (getpagesize())
#define E_NO_SPACE            1
#define E_CORRUPT_FREESPACE   2
#define E_PADDING_OVERWRITTEN 3
#define E_BAD_ARGS            4
#define E_BAD_POINTER         5

int m_error;
void *ptr;
typedef struct __header_t {
    int size;
    int magic;
} header_t;

typedef struct __node_t{
	int size;
	struct __node_t *next;
}node_t;
node_t *head;

// node_t *head = mmap(NULL, 4096, PROT_READ|PROT_WRITE,
//                     MAP_ANON|MAP_PRIVATE, -1, 0);
// head->size   = 4096 - sizeof(node_t);
// head->next   = NULL;
// grow the heap
//mmap返回地址
// pagesize
// int mem_init(int size_of_region){
// 	static int call_times=0;
// 	++call_times;
// 	if(size_of_region<=0 || call_times>=2){
// 		m_error=4;
// 		return -1;
// 	}
// 	// open the /dev/zero device
// 	int fd = open("/dev/zero", O_RDWR);
// 	if(fd==-1)
// 		write(STDERR_FILENO,"open error\n",20);
// 	printf("%d\n",fd);
// 	// // size_of_region (in bytes) needs to be evenly divisible by the page size
// 	ptr=mmap(NULL, size_of_region, PROT_READ | PROT_WRITE, MAP_PRIVATE|MAP_FIXED , fd, 0);
// 	printf("%p\n",(void*)MAP_FAILED);
// 	printf("%p\n",(char*)ptr);
// 	if (ptr == MAP_FAILED){
// 		perror("mmap");
// 		exit(1);
// 	}
// 	// // close the device (don't worry, mapping should be unaffected)
// 	close(fd);
// 	printf("done\n");
// 	// head=(node_t*)ptr;
// 	// head->size   = 4096 - sizeof(node_t);
// 	// head->next   = NULL;
// 	return 0;
// }


int main()
{
	// printf("pagesize :%d\n",PAGESIZE);
 //    mem_init(PAGESIZE);
	int fd;
	if((fd=open("/users/fangpin/Documents/programs/c/test.txt",O_RDWR))==-1)
		perror("mmap");
	void *ptr=mmap(NULL,getpagesize()*8,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
	if(ptr==MAP_FAILED){
		perror("map\n");
		exit(1);
	}
	printf("%p\n",ptr);
    return 0;
}