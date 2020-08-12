#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argv,char* argc[])
{
	int a,i;
	if(fprintf(stdout,"please enter a number:\n")<0)
	{
		perror("fail");
		exit(-1);
	}
	if((fscanf(stdin,"%d",&a))<0)
	{
		perror("fail");
		exit(-1);
	}
	printf("a=%d\n",a);
	for(i=0;i<argv;i++)
		printf("argc[%d]=%s\n",i,argc[i]);
	if(a<0)
	{
		fprintf(stderr,"the number must > 0\n");
	//	perror("the number must > 0\n");
	}
	return 0;
}
