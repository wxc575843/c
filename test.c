#include <stdio.h>
#include <stdlib.h>

int main(void){
	int b=1;
	void *pa=(void*)&b,*pb=(void*)&b;
	printf("%d\n",pa==pb);
}