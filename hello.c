#include <stdio.h>  
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main()  
{  
    int fd[2];
    pipe(fd);
    char *argv[5]={"ls","-l",NULL,"wc",NULL};
    int pid=fork();
    switch(pid){
        case 0:
            dup2(fd[1],STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            execvp(argv[0],argv);
            break;
        default:
            dup2(fd[0],STDIN_FILENO);
            close(fd[0]);
            close(fd[1]);
            while(wait(NULL)>0);
            execvp(argv[3],&argv[3]);
            break;
    }
    return 0;
}  