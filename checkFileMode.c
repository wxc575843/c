#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int agrc,char *argv[]){
	int i;
	struct stat buf;
	char *ptr;
	for(i=1;i<agrc;++i){
		lstat(argv[i],&buf);
		if(S_ISDIR(buf.st_mode))
			ptr="dir";
		else if(S_ISREG(buf.st_mode))
			ptr="reg";
		else if(S_ISFIFO(buf.st_mode))
			ptr="fifo";
		else if(S_ISBLK(buf.st_mode))
			ptr="blk";
		else if(S_ISLNK(buf.st_mode))
			ptr="link";
		else if(S_ISSOCK(buf.st_mode))
			ptr="sock";
		else if(S_ISCHR(buf.st_mode))
			ptr="char";
		else 
			ptr="unknown";
		puts(ptr);
	}
	return 0;
}