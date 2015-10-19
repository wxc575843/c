#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
const int MAXN=550;
char* homePath,curPath[513];
char *newline="\n";
char error_message[30] = "An error has occurred\n";

int getargs(int *argc,char **argv,char *input,int *redpos,int flag){
	char *in=NULL;
	int i,j;
	if(strchr(input,'\n')==NULL){
		write(STDERR_FILENO, error_message, strlen(error_message));
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
		write(STDERR_FILENO, error_message, strlen(error_message));
		return 0;
	}
	*argc=i;
	if(!flag)
		write(STDOUT_FILENO,input,strlen(input));
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
			}
			if(strcmp(argv[0],"wait")==0)
				exit(0);
			else if(strcmp(argv[0],"pwd")==0){
				if(argc>1){
					write(STDERR_FILENO, error_message, strlen(error_message));
					exit(0);
				}
				write(STDOUT_FILENO,curPath,strlen(curPath));
				write(STDOUT_FILENO,newline,strlen(newline));
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
						write(STDERR_FILENO, error_message, strlen(error_message));
					else{
						close(STDOUT_FILENO);
						int fd=open(argv[redpos+1],O_CREAT|O_TRUNC|O_WRONLY,(S_IRWXU^S_IXUSR)|S_IRGRP|S_IROTH);
						if(fd==-1){
							write(STDOUT_FILENO,error_message,strlen(error_message));
							exit(0);
						}
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
				waitpid(pid,NULL,0);
			break;
	}
}

void start(int flag){
	char *argv[MAXN];
	char input[MAXN];
	while(1){
		int argc=0,redpos=0;
		write(STDOUT_FILENO,"mysh >",6);
		if(fgets(input,MAXN-1,stdin)==NULL)
			break;
		if(!flag)
			write(STDOUT_FILENO,input,strlen(input));
		if(getargs(&argc,argv,input,&redpos,flag) && argc>0){
			if(strcmp(argv[0],"exit")==0){
				if(argc!=1)
					write(STDERR_FILENO, error_message, strlen(error_message));
				else break;
			}
			execute(argc,argv,redpos);
		}
	}
}

int main(int argc,char *argv[]){
	homePath=getenv("HOME");
	getcwd(curPath,MAXN-1);
	int i;
	if(argc>1){
		for(i=1;i<argc;++i){
			close(STDIN_FILENO);
			if(open(argv[i],O_RDONLY)!=-1)
				start(0);
			else 
				write(STDOUT_FILENO,error_message,strlen(error_message));
		}
	}
	else 
		start(1);
	return 0;
}
