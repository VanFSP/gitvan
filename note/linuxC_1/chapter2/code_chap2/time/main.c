#include<stdio.h>
#include<time.h>

int main()
{
	time_t the_time;
	char *c_time;
	time(&the_time);
	c_time=ctime(&the_time);
	printf("the time is %ld seconds\nthe correct format of time is %s",the_time,c_time);
	return 0;
}
