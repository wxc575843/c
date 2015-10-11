#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
	char a[]="abc",b[]="def";
	int fd=open("./out.c",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
	int seek=lseek(fd,0,SEEK_CUR);
	pwrite(fd,a,sizeof(a),seek);
	seek=lseek(fd,sizeof(a),SEEK_CUR);
	pwrite(fd,b,sizeof(b),seek);
	return 0;
}