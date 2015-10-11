#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "sort.h"

int cmp(const void *x,const void *y){
	return (long long)(((rec_t*)x)->key) - (long long)(((rec_t*)y)->key);
}

int main(int argc,char** argv){
	if(argc!=3){
		perror("arguments");
		exit(1);
	}
	struct stat cnt;
	stat(argv[1],&cnt);
	int rc=0,wc,len=cnt.st_size/sizeof(rec_t);
	int fd=open(argv[1],O_RDONLY);
	rec_t *toComp=(rec_t*)malloc(sizeof(rec_t)*len);
	int pos=0;
	while((rc=read(fd,&toComp[pos],sizeof(rec_t)))>0){
		if(rc==-1) 
			perror("read");//read wrong
		++pos;
	}
	close(fd);
	qsort(toComp,len,sizeof(rec_t),cmp);
	int fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
	if(fd2<0)
		perror("open");
	int i;
	for(i=0;i<len;++i){
		wc=write(fd2,&toComp[i],sizeof(rec_t));
		if(wc<0)
			perror("write");
	}
	close(fd2);
	free(toComp);
}
