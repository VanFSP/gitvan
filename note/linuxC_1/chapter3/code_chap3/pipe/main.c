#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	if(mkfifo("./my_fifo2",0777)==0)
		printf("FIFO file creation success !\n");
	else
		fprintf(stdout,"FIFO file creation failed !\n");
	exit(EXIT_SUCCESS);
}
