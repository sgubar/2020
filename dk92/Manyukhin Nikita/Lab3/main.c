#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tool.h"

int main()
{
    int aSize;
    int aKey;
    int operation;

    printf("Please Enter the Size of Array(0-10000): ");
    do
    {
        scanf("%d", &aSize);
        if (aSize < 0 || aSize > 100000) printf("Error! Enter another: ");
    }while (aSize < 0 || aSize > 100000);

    int *Array = (int *) malloc(sizeof(int) * aSize);
    if(Array == 0)
	{
		printf("ERROR\n");
		return 1;
	}

	for (operation = 0; operation <= 2; operation++)
    {
        clock_t start, end, time;
        switch(operation)
        {
        case 0:
            ArrayFilling (Array, aSize);
            printArrayToFile(Array, aSize, "unSortedArray.txt");
            break;
        case 1:
            start = clock();
            QuickSort(Array, 0, aSize - 1);
            end = clock();
            time = (end - start);
            printf("QuickSort Func Time: %dms\n", time);
            printArrayToFile(Array, aSize, "SortedArray.txt");
            break;
        case 2:
            printf("Please enter the number you want to find: ");
            scanf("%d", &aKey);
            start = clock();
            LinearSearch (Array, aKey, aSize);
            end = clock();
            time = (end - start);
            printf("LinearSearch Func Time: %dms\n", time);
            break;
        }
    }
}
