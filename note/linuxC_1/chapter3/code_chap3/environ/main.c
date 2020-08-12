#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* c;
	printf("hello\n");
	c=getenv(PATH);
	printf("%s\n",c);
	return 0;
}
