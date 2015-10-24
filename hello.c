#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int fd[2];

int main()
{
    printf("%d\n",is_dir("\bin"));
    return 0;
}