#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
int main(int argv,char* argc[])
{
	printf("argv is %d \n",argv);
	int i;
	for(i=0;i<argv;i++)
	{
		printf("argc[%d] is %s\n",i,argc[i]);
	}
	struct stat file_name;
	if(stat(argc[0],&file_name)==0)
	{
		printf("s_uid=%d\ns_gid=%d\n",file_name.st_mode&S_ISUID,file_name.st_mode&S_ISGID);
	}
	printf("uid=%d\ngid=%d\neuid=%d\negid=%d\n",getuid(),getgid(),geteuid(),getegid());
	return 0;//代表主函数成功执行并且返回给操作系统一个值0
}
