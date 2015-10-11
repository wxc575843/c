#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//get shell commands and if it's build-in return 1,else if it's white line return -1,else return 0;
int getShellCommand(char input[],char** op){
    int j=strlen(input),i=0;
    --j;
    while((input[i]==' ' || input[i]=='\t') && i<j) //erase the front spaces
        ++i;
    while((input[j]==' '|| input[i]=='\t') && j>=i) //erase the behind spaces
        --j;
    if(j<i) return -1;								//white line
    int head=i;										//the start of the shell commands
    int k=0;										//couts the number of words consisting of the shell command
    while(i<j){
        while(input[i]==' ' || input[i++]=='\t');	//the start of a word
        head=i-1;
        while(input[i]!=' ' && input[i++]!='\t');	//the end of a word
        input[i]='\0';								//cstring ends with 0
        ++i;
        op[k++]=&input[head];
    }
    op[k]=NULL;
    return 1;
}

int main(int argc,char** argv){
    char input[515];
    while(1){
        printf("mysh> ");
        gets(input);								//read data
        if(!strcmp(input,"exit")){					//exit
            return 0;
        }
        char* op[100];								//contains shell commands
        int commandState=getShellCommand(input,op);	//get the shell commands and judge if it's build-in
        int rc;
        switch(commandState){
            case 1:									//a legal command
                rc=fork();
                if(rc<0){							//fork() failed
                    perror("fork\n");
                    exit(1);
                }
                else if(rc==0){						//child process
                    execvp(op[0],op);
                }
                else{								//parent process
                    wait(0);
                }
                break;
        }
    }
    return 0;
}
