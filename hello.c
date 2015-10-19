#include <stdio.h>  
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char *argv[])  
{  
    char input[100];
    // chdir("/c");
    // if(argc >1){
    //     fclose(STDIN_FILENO);
    //     open(argv[1],O_RDONLY);
    //     int cnt=0;
    //     char * s;
    //     while((s=fgets(input,100,stdin))!=NULL){
    //         // if(input[0]==NULL)
    //         //     break;
    //         puts(s);
    //         ++cnt;
    //         if(cnt==2)
    //             break;
    //         // puts(input);
    //     }
    // }
    while(fgets(input,100,stdin)!=NULL);
    return 0;
}  