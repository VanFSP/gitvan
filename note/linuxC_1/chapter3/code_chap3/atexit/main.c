#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <unistd.h>

int main(int argc,char*argv)
{
	atexit(func1);//注册终止处理函数func1()
	atexit(func2);//注册终止处理函数func2()
	atexit(func3);//注册终止处理函数func3()
	//完成所有的终止处理函数后，再进行I/O的清理函数，最后调用_exit函数返回内核
	printf("process exit\n");
	printf("id=%d",getpid());
	return 0;//正常终止进程生命周期
}
