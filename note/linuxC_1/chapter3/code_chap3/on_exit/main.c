#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int i,j,k;

int main(int argc,char*argv)
{
	i=3;
	on_exit(func1,(void*)&i);//注册终止处理函数func1()
	j=4;
	on_exit(func2,(void*)&j);//注册终止处理函数func2()
	k=5;
	on_exit(func3,(void*)&k);//注册终止处理函数func3()
	//完成所有的终止处理函数后，再进行I/O的清理函数，最后调用_exit函数返回内核
	/*
	当用户在shell中执行可执行文件，linux操作系统会产生一个进程，进程从main函数执行，
	依次注册func1,func2,func3函数，并且把i，j，k作为参数传递给对应的终止处理函数，
	main函数通过在标准输出上显示字符串后，通过return返回来创造进程生命周期的终止，
	在退出到内核之前，会触发预先注册的终止处理函数的回调，最先注册的函数最后回调
	printf("process exit\n");
	return 0;//正常终止进程生命周期
}
