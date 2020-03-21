#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortTools.h"
#include "tools.h"

void values(int *aArray, int aSize)
{
	srand(time(NULL));
	int i = 0;
	for(; i < aSize; i++)
		aArray[i] = rand();
}

void sortArray(int *aArray, int aSize, FILE*file)
{

    clock_t start, end;
    double time;


    start = clock();
    BubbleSort(aArray, aSize);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("BubbleSort Time: %.5lfs\n", time);
    fprintf(file, "BubbleSort Time: %.5lfs\n", time);

    start = clock();
    SelectionSort(aArray, aSize);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("SelectionSort Time: %.5lfs\n", time);
    fprintf(file, "SelectionSort Time: %.5lfs\n", time);

    start = clock();
    InsertionSort(aArray, aSize);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("InsertionSort Time: %.5lfs\n", time);
    fprintf(file, "InsertionSort Time: %.5lfs\n", time);
}



