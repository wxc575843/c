#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char** argv){
	if(argc!=2){
		perror("wrong arg");
		exit(1);
	}
	int size=atoi(argv[1]);
	char *buf=(char*)malloc(size);
	if(buf==NULL){
		perror("malloc wrong");
		exit(1);
	}
	int rc;
	while((rc=read(0,buf,size))==size){
		if(write(1,buf,size)<0){
			perror("write error");
			exit(1);
		}	
	}
	if(rc<0){
		perror("no loop");
		exit(1);
	}
}
