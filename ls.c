#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc,char *argv[]){
	DIR *dp;
	struct dirent *dirp;
	if(argc!=2){
		errno=ENOENT;
		perror("wrong args");
		// fprintf(stderr,"wrong args\n");
		exit(1);
	}
	if((dp=opendir(argv[1]))==NULL){
		fprintf(stderr,"wrong dir\n");
		exit(1);
	}
	while((dirp=readdir(dp))!=NULL){
		printf("%s\n",dirp->d_name);
	}
	closedir(dp);
	return 0;
}