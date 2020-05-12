#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Gen.h"
#include "Sort.h"

long quicksort(char* array,int l,int r, int t)
{
	int sizeOf = 0;
	for(int a = 0; *(array + a) != NULL; a++)sizeOf++;
		clock_t theStart0 = clock();
        int i=l, j=r;
    	int d;
    	int m=array[(l+r)/2];
    	while(i<=j)
    	{
        	for(; array[i]<m; i++);
        	for(; array[j]>m; j--);
        	if(i<=j)
        	{
            	d=array[i];
            	array[i++]=array[j];
            	array[j--]=d;
        	}
    	}
    	if(l<j) quicksort(array,l,j,t);
    	if(i<r) quicksort(array,i,r,t);
    	clock_t theEnd0 = clock();
	if(t == 1){
	for (int b = 0; b < sizeOf; ++b)
	{
		printf("%c", *(array + b + 1));
	}
	}
	int s = ((double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
  	return s;
}