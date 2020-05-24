#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

int main(int argc, char *argv[]) 
{
	ArrayInfo *info = randomStrArray(20, 20);
	printArray(info);
	sort(info);
	printArray(info);
	int d = Search(info, info->Array[10]);
	printf("%i\n", d);	
	freeArray(info);
	return 0;
}
