#include <stdio.h>  
#include <unistd.h>
int main()  
{  
    for(int j=0;j<3;j++)  
    {  
        for(int i=0;i<5;i++)  
        {  
            printf("-");  
            sleep(2);  
        }  
        sleep(2);  
        printf("@\n");  
    }  
}  