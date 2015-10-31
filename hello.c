#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int agrc,char *argv[]){
	FILE* fp=tmpfile();
	fputs("a single line\n",fp);
	rewind(fp);
	char line[100];
	fgets(line,100,fp);
	puts(line);
	return 0;
}