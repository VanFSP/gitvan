#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Runing ps with system\n");
	system("ps ax &");
	printf("Done.\n");
	exit(0);
}

