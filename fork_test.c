#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
//产生新进程和父进程执行顺序不定

int main(int argc, char** argv){
	printf("start in process: %d\n",(int)getpid());
	int rc=fork();
	if(rc<0){//如进程数限制
		perror("fork");
		exit(1);
	}
	else if(rc>0){
	//	sleep(1);
		// wait(0);
		printf("i'm parent pid=%d\n",(int)getpid());
		// printf("i hava a child %d\n",rc);
	}
	else{//rc==0
		// char* arg[3];
		// arg[0]="wc";
		// arg[1]="fork_test.c";
		// arg[2]=NULL;
		printf("i'm child pid=%d\n",(int)getpid());
		// printf("do someting\n");
		// execvp(arg[0],arg);
		// printf("this should be not input!");
		// printf("rc  %d\n",rc);
	}
	return 0;
}
