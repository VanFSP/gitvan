#include "func.h"
#include <stdio.h>

void func1(int status,void*arg)
{
	printf("func1 is called\n");
	printf("func1 exit status is %d\n",status);
	printf("func1 arg is %d\n",*((int*)arg));
}

void func2(int status,void*arg)
{
	printf("func2 is called\n");
	printf("func2 exit status is %d\n",status);
	printf("func2 arg is %d\n",*((int*)arg));
}

void func3(int status,void *arg)
{
	printf("func3 is called\n");
	printf("func3 exit status is %d\n",status);
	printf("func3 arg is %d\n",*((int*)arg));
}
