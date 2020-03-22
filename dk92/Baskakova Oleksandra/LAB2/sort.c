#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include "selection.h"
#include "insertion.h"
#include "buble.h"
#include "sortResult.c"
#include "tools.h"

int *copyArray(int *array, int size);
void fprintResult(FILE *file, char label[], SortResult result, int size);
void swap(int *arr, int firtsIndex, int secondIndex);

int main(int argc, char const *argv[])
{
    int size;
    //replace with smart validation
    do
    {
        printf("enter size of array \n");
    } while (!scanf("%d", &size));

    // initialization
    srand(time(NULL));
    int *array = fillArray(size);
    SortResult unsorted;
    unsorted.array = array;
    unsorted.ellapsedTime = 0;

    //sorting
    SortResult bubleSorted = bubleSort(array, size);
    SortResult selectionSorted = selectionSort(array, size);
    SortResult insertionSorted = insertionSort(array, size);

    // output
    FILE *file = fopen("result.txt", "w");
    fprintResult(file, "unsorted array\n", unsorted, size);
    fprintResult(file, "buble sorted array\n", bubleSorted, size);
    fprintResult(file, "selection sorted array\n", selectionSorted, size);
    fprintResult(file, "insertion sorted array\n", insertionSorted, size);
    fclose(file);

    // free resources
    free(array);
    free(bubleSorted.array);
    free(selectionSorted.array);
    free(insertionSorted.array);
    return 0;
}
