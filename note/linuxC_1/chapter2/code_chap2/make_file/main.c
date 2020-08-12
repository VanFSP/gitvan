#include <stdio.h>
#include "max.h"
#include "min.h"

int main(int argv,char* argc[])
{
	printf("1 和 5 的较大者是：%d\n",max(1,5));
	printf("1 和 5 的较小者是：%d\n",min(1,5));
	return 0;
}
