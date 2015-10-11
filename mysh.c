#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
const int MAXN=513;

int getargs(int *argc,char **argv,int *ok){
	char input[MAXN];
	char *in=NULL;
	int i;
	*ok=0;
	if(fgets(input,MAXN-1,stdin)==NULL){
		*ok=1;
		return 0;
	}
	if(strchr(input,'\n')==NULL){
		*ok=0;
		printf("input is too long!\n");
		return 0;
	}
	int len=strlen(input);
	input[len-1]='\0';
	printf("%s\n",input);
	in=input;
	for(i=0;i<MAXN-1;++i){
		if((argv[i]=strtok(in," \t\n"))==NULL)
			break;
		// printf("%d: %s\n",i,argv[i]);
		in=NULL;
	}
	if(i>MAXN-1){
		printf("to many args\n");
		return 0;
	}
	*argc=i;
	return 1;
}

void execute(int agrc,char **argv){
	printf("previous: %s\n",argv[0]);
	int pid=fork();
	switch(pid){
		case -1:
			perror("fork\n");
			exit(1);
			break;
		case 0:
			printf("child: %s\n",argv[0]);
			execvp(argv[0],argv);
			break;
		default:
			printf("parent: %s\n",argv[0]);
			wait(NULL);
			break;
	}
}

int main(void){
	int argc;
	char *argv[MAXN];
	int ok;

	while(1){
		printf("mysh> ");
		if(getargs(&argc,argv,&ok) && argc>0){
			execute(argc,argv);
		}
		else printf("\n");
	}
	return 0;
}
