#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define path "/home/gideon/note/linuxC_1/chapter3/code_chap3/atexit/main"
#define pa_th "/bin/ls"

int main()
{
	pid_t pid;
	int *statloc;
	char *argv[]={NULL};
	pid=fork();
	if(pid==-1)
		printf("fork error\n");
	printf("enter main process ---\n");
//	else if(pid==0){
	if(pid==0){
		printf("the returned value is %d\n",pid);
		printf("in child process\n");
		printf("my PID is %d\n",getpid());
//		execl(pa_th,"ls","-l",NULL);
		execv(path,argv);
		//会发现执行execl函数后以下的程序将会被新的可执行程序覆盖
		printf("exiting main process ---\n");
		printf("此行代码所在的内存(即代码段)被覆盖");
	}
//	else
//	{
//		printf("the returned value is %d\n",pid);
//		printf("in father process\n");
//		printf("my PID is %d\n",getpid());
//	}
	printf("hello\n");
	return 0;
}
