#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc,char *argv[]){
	char *path="/abx";
	struct stat buf;
	lstat(path,&buf);
	if(S_ISDIR(buf.st_mode) || S_ISREG(buf.st_mode))
		puts("yes");
	return 0;
}