#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int agrc,char *argv[]){
	char buf[1000];
	int rc=readlink("/c",buf,sizeof(buf));
	if(rc<0){
		fprintf(stderr,"readlink error\n");
	}
	else printf("%s\n",buf);
	return 0;
}