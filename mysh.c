#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
const int MAXN=550;
char* homePath,*curPath;

int getargs(int *argc,char **argv,char *input,int *redpos){
	char *in=NULL;
	int i,j;
	if(fgets(input,MAXN-1,stdin)==NULL)
		return 0;
	if(strchr(input,'\n')==NULL){
		printf("input is too long!\n");
		return 0;
	}
	int len=strlen(input);
	--len;
	input[len]='\0';
	for(int i=0;i<len;++i){
		if(input[i]=='<' || input[i]=='>' || input[i]=='&'){
			for(j=len+1;j>i;--j){
				input[j]=input[j-2];
			}
			input[i+1]=input[i];
			input[i+2]=' ';
			input[i]=' ';
			++i;
			len+=2;
			input[len]=0;
		}
	}
	in=input;
	for(i=0;i<MAXN-1;++i){
		if((argv[i]=strtok(in," \t\n"))==NULL)
			break;
		if((!strcmp(argv[i],">") || !strcmp(argv[i],"<")) && !*redpos)
			*redpos=i;
		in=NULL;
	}
	if(i>MAXN-1){
		printf("to many args\n");
		return 0;
	}
	*argc=i;
	return 1;
}

void execute(int argc,char **argv,int redpos){
	int flag=strcmp(argv[argc-1],"&"),stat;
	int pid=fork();
	switch(pid){
		case -1:
			fprintf(stderr,"fork error\n");
			exit(1);
		case 0:
			for(int i=0;i<argc;++i){
				if(argv[i][0]=='$' && getenv(&argv[i][1]))
					argv[i]=getenv(&argv[i][1]);
			}
			if(!flag){
 				argv[--argc]=NULL;
				usleep(100000);
			}
			if(strcmp(argv[0],"wait")==0)
				exit(0);
			if(strcmp(argv[0],"exit")==0){
				if(argc!=1){
					printf("wrong args\n");
				}
				exit(0);
			}
			else if(strcmp(argv[0],"pwd")==0){
				if(argc>1){
					printf("wrong args\n");
					exit(0);
				}
				printf("%s\n",curPath);
			}
			else if(strcmp(argv[0],"cd")==0){
				if(argc>1){
					chdir(argv[1]);
					getcwd(curPath,MAXN);
				}
				else{
					chdir(homePath);
					getcwd(curPath,MAXN);
				}
			}
			else{
				if(!redpos)
					execvp(argv[0],argv);
				else{
					if(argc-redpos!=2)
						printf("wrong args\n");
					else{
						close(STDOUT_FILENO);
						int fd=open(argv[redpos+1],O_CREAT|O_TRUNC|O_WRONLY,(S_IRWXU^S_IXUSR)|S_IRGRP|S_IROTH);
						argv[redpos]=NULL;
						execvp(argv[0],argv);
					}
				}
			}
			break;
		default:
			if(strcmp(argv[0],"wait")==0){
				while(wait(&stat)>0);
				break;
			}
			else if(flag)
				wait(NULL);
			break;
	}
}

int main(void){
	char *argv[MAXN];
	char input[MAXN];
	homePath=getenv("HOME");
	curPath=getenv("HOME");
	chdir(homePath);
	while(1){
		int argc=0,redpos=0;
		printf("%s  mysh> ",curPath);
		fflush(stdout);
		if(getargs(&argc,argv,input,&redpos) && argc>0)
			execute(argc,argv,redpos);
	}
	return 0;
}
