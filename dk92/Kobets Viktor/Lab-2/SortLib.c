#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "InputSort.h"
#include "SortLib.h"

long bubblesort(char *array)
{
	int sizeOf = 0;
	for(int a = 0; *(array + a) != NULL; a++)sizeOf++;	
	char array2;
	struct timespec start, finish; 
    clock_gettime(CLOCK_REALTIME, &start);
	for(int i = 0; i < sizeOf; i++)
	{
		for (int j = 0; j < sizeOf - i; j++)
		{
			if(*(array + j) > *(array + j + 1))
			{
				array2 = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = array2;
			}
		}	
	}
	clock_gettime(CLOCK_REALTIME, &finish); 
	long seconds = finish.tv_sec - start.tv_sec; 
	long ns = finish.tv_nsec - start.tv_nsec;
	if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds; 
    } 
	for (int b = 0; b < sizeOf; ++b)
	{
		printf("%c", *(array + b + 1));
	}
	printf("\n");
	return ns;
}

long choosesort(char *array)
{
	int sizeOf = 0;
	for(int a = 0; *(array + a) != NULL; a++)sizeOf++;
	struct timespec start, finish; 
    clock_gettime(CLOCK_REALTIME, &start);
	for (int i = 0; i < sizeOf; ++i)
	{
		int minimum = i;
		for (int j = i + 1; j < sizeOf; ++j)
		{
			if (*(array + j) < *(array + minimum))
			{
				minimum = j;
			}
		}
		char array2;
		array2 = *(array + i);
		*(array + i) = *(array + minimum);
		*(array + minimum) = array2;
	}
	clock_gettime(CLOCK_REALTIME, &finish); 
	long seconds = finish.tv_sec - start.tv_sec; 
	long ns = finish.tv_nsec - start.tv_nsec;
	if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds;
    } 
	for (int b = 0; b < sizeOf; ++b)
	{
 		printf("%c", *(array + b));
	}
	printf("\n");
	return ns;
}

long pastesort(char *array)
{
	int sizeOf = 0, keylement = 0;
	for(int a = 0; *(array + a) != NULL; a++)sizeOf++;
	int index;
	char max;
	struct timespec start, finish; 
    clock_gettime(CLOCK_REALTIME, &start);
	for (int i = 1; i < sizeOf; i++){
    	max = *(array+i);
    	index = i-1;
    	while(index >= 0 && *(array+index) > max){
       	 	*(array+index + 1) = *(array+index); 
        	*(array+index) = max;
        	index--;
    	}	
	}
	clock_gettime(CLOCK_REALTIME, &finish); 
	long seconds = finish.tv_sec - start.tv_sec; 
	long ns = finish.tv_nsec - start.tv_nsec;
	if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds;
    } 
	for (int b = 0; b < sizeOf; ++b)
	{
 		printf("%c", *(array + b));
	}
	printf("\n");
	return ns;
}