#include <stdio.h>
#include <unistd.h>
extern char** environ;

int main(int argc,char** argv){
	setbuf(stdout,NULL);
	execl("/bin/echo","echo","the","lazy","dogs",NULL);
	execlp("echo","echo","execlp",NULL);
	char *op[10]={"echo","echo","execvp",NULL};
	execvp(op[0],op);
	return 0;
}