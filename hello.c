#include <stdio.h>  
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main()  
{  
    char *argv[]={"x",NULL};
    execvp(argv[0],argv);
    return 0;
}  