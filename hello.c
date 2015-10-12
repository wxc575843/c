#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void){
	char *argv[3]={"ls","-l",NULL};
	execvp(argv[0],argv);
	return 0;
}