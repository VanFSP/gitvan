#include<stdio.h>
#include<sys/stat.h>
#include<malloc.h>
#include<stdlib.h>

#define filepath "/etc/passwd"
#define FILEPATH "/home/gideon/code/Ctest/two_level_pointer.c"

int main()
{
	int  a;
/*
//	当使用结构体指针并且文件在家目录时，发现程序终止，即发出SIGABRT信号
	struct stat *buf;
	buf=(struct stat*)malloc(sizeof(stat));
	if(buf==NULL)
		exit(-1);
*/
	struct stat buf;
	a=stat(FILEPATH,&buf);
	if(a==0)
	{
		printf("uid=%d\nino=%d\n",buf.st_uid,buf.st_ino);
		/*
		printf("uid=%d\nino=%d\n",buf->st_uid,buf->st_ino);
		free(buf);
		*/
	}
	else
	{
		printf("%d",a);
		exit(-1);
	}
	return 0;
}
