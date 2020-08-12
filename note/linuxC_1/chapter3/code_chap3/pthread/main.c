#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

char str[]="hello";
sem_t bin_sem;//使用信号量来进行同步
pthread_mutex_t work_mutex;//使用互斥量来进行同步
char work_area[100];

void * childthread(void* arg)
{
	int i;
	printf("thread %d is running.\n",pthread_self());
	printf("argument is %s.\n",(char *)arg);

	printf("bin_sem_child=%x\n",bin_sem);
	if(sem_wait(&bin_sem)!=0)
	{
		perror("无法申请资源\n");
		exit(EXIT_FAILURE);
	}//V操作

	printf("work_mutex_child=%d\n",work_mutex);
	pthread_mutex_lock(&work_mutex);//加锁

	printf("临界资源数组work_area是%sbin_sem_child=%x\n",work_area,bin_sem);
	printf("work_mutex_child=%d\n",work_mutex);

	pthread_mutex_unlock(&work_mutex);//解锁
	printf("work_mutex_child=%d\n",work_mutex);

	for(i=0;i<10;i++)
	{
		printf("childthread message.\n");
		sleep(2);//2秒
	}
	pthread_exit("ok");
}

int main(int arg,char* argv[])
{
	printf("process %d is running.\n",getpid());
	pthread_t tid;
	void *receive_thread_exit;
	if(sem_init(&bin_sem,0,0)!=0)
	{
		perror("semaphore initialization failed\n");
		exit(EXIT_FAILURE);
	}

	if(pthread_mutex_init(&work_mutex,NULL)!=0)
	{
		perror("Mutex initializatioin failed\n");
		exit(EXIT_FAILURE);
	}

	printf("create a childthread ---\n");
	if(pthread_create(&tid,NULL,childthread,(void*)str)!=0)
	{
		perror("Thread creation failed.\n");
		exit(EXIT_FAILURE);
	}

	printf("work_mutex=%d\n",work_mutex);
	pthread_mutex_lock(&work_mutex);//加锁

	printf("enter a string:\n");
	fgets(work_area,100,stdin);

	pthread_mutex_unlock(&work_mutex);//解锁
	printf("work_mutex=%d\n",work_mutex);

	if(sem_post(&bin_sem)!=0)
	{
		perror("无法释放资源\n");
		exit(EXIT_FAILURE);
	}//P操作
	printf("bin_sem=%x\n",bin_sem);


	if(pthread_join(tid,&receive_thread_exit)!=0)
	{
		perror("pthread join failed.\n");
		exit(EXIT_FAILURE);
	}

	printf("exiting childthread ---%d\n",tid);
	printf("it returned %s.\n",(char *)receive_thread_exit);
	sem_destroy(&bin_sem);
	pthread_mutex_destroy(&work_mutex);
	printf("exiting process %d.\n",getpid());
	return 0;
}

