#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[]){
	if(argc!=3){
		fprintf(stderr,"wrong agrs\n");
		exit(1);
	}
	// printf("%s\n",argv[1]);
	int in=open(argv[1],O_CREAT|O_RDONLY);
	if(in<0){
		fprintf(stderr,"open_err\n");
		exit(1);
	}
	int out=open(argv[2],O_CREAT|O_RDWR|O_TRUNC,S_IRUSR|S_IWUSR);
	if(out<0){
		fprintf(stderr,"open error\n");
		exit(1);
	}
	char buf[10000];
	int rc=0;
	while((rc=read(in,buf,sizeof(buf)))!=0){
		if(rc<0){
			fprintf(stderr,"read error\n");
			exit(1);
		}
		rc=write(out,buf,rc);
		if(rc<0){
			fprintf(stderr,"write error\n");
			exit(1);
		}
	}
	close(in);
	close(out);
	return 0;
}