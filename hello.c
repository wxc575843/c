#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int agrc,char *argv[]){
	struct stat buf;
	lstat(argv[1],&buf);
	if(buf.st_mode & S_ISUID)
		puts("suid");
	return 0;
}