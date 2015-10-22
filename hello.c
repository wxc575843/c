#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int fd[2];
void run_ls()
{
      dup2(fd[1],1);
     close(fd[0]);
     // close(fd[1]);
     char *argv[]={"ls",NULL};
     execvp("ls",argv);
}
void run_wc()
{
      dup2(fd[0],0);
     // close(fd[0]);
     close(fd[1]);
     char *argv[]={"wc",NULL};
     execvp("wc",argv);
}
int main()
{
    pipe(fd);
    printf("%d %d\n",fd[0],fd[1]);
    if(fork()==0)
        run_ls();
    else
        run_wc();
     return 0;
}