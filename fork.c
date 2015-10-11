#include <unistd.h>
#include <stdio.h>

int main(void){
	setbuf(stdout,NULL);
	printf("test fork\n");
	int rc=fork();
	printf("return %d\n",rc);
	return 0;
}