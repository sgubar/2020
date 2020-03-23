#include "tools.h"

int *fillArray(int size)
{
    int *array = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
         array[i] = rand()%10000;
    }
    return array;
}

int *copyArray(int *array, int size)
{
    int intSize = sizeof(int);
    int *copiedArray = (int *)calloc(size, intSize);
    memcpy(copiedArray, array, size * intSize);
    return copiedArray;
}

void fprintResult(FILE *file, char label[], SortResult result, int size)
{
    fputs(label, file);
    fprintf(file, "elapsed time: %d\n", result.ellapsedTime);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d: %d\n", i, result.array[i]);
    }
}

void swap(int *arr, int firtsIndex, int secondIndex)
{
    int tmp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = tmp;
}
