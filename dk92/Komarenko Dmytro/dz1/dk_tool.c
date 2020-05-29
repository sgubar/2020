#include "dk_tool.h"
#include <stdio.h>
int reversal(int arr[],int len)
{
    int i;
	int swap=0;
	for ( i= 0; i < len/2; i++)
	{
		swap = arr[i];
		arr[i] = arr[len - i-1];
		arr[len - i-1] = swap;
	}
	return arr;
}
