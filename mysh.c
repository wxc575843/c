#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
const int MAXN=513;

int getargs(int *argc,char **argv){
	char input[MAXN];
	char *in=NULL;
	int i;
	if(fgets(input,MAXN-1,stdin)==NULL)
		return 0;
	if(strchr(input,'\n')==NULL){
		printf("input is too long!\n");
		return 0;
	}
	int len=strlen(input);
	input[len-1]='\0';
	in=input;
	for(i=0;i<MAXN-1;++i){
		if((argv[i]=strtok(in," \t\n"))==NULL)
			break;
		in=NULL;
	}
	if(i>MAXN-1){
		printf("to many args\n");
		return 0;
	}
	*argc=i;
	return 1;
}

void execute(int argc,char **argv){
	// printf("previous: %s\n",argv[0]);
	int i;
	for(i=0;i<argc;++i){
		// printf("argv : %s\n",argv[i]);
		int len=strlen(argv[i]);
	}
	int pid=fork();
	switch(pid){
		case -1:
			perror("fork\n");
			exit(1);
			break;
		case 0:
			// printf("child: %s\n",argv[0]);
			// for(i=0;i<=argc;++i)
			// 	printf("argv : %s\n",argv[i]);
			execvp(argv[0],argv);
			break;
		default:
			// printf("parent: %s\n",argv[0]);
			// for(i=0;i<=argc;++i)
			// 	printf("argv : %s\n",argv[i]);
			wait(NULL);
			break;
	}
}

int main(void){
	int argc;
	char *argv[MAXN];

	while(1){
		printf("mysh> ");
		if(getargs(&argc,argv) && argc>0){
			execute(argc,argv);
		}
		else printf("\n");
	}
	return 0;
}
