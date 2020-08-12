#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid==-1)
		printf("fork error\n");
	else if(pid==0){
		printf("the returned value is %d\n",pid);
		printf("in child process\n");
		printf("my PID is %d\n",getpid());
		exit(-1);
	}
	else
	{
		printf("the returned value is %d\n",pid);
		printf("in father process\n");
		printf("my PID is %d\n",getpid());
	}
	printf("hello\n");
	return 0;
}
