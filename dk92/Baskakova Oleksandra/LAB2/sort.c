#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>

typedef struct SortResult
{
    int *array;
    int iterations;
} SortResult;

int *fillArray(int size);
SortResult bubleSort(int *array, int size);
SortResult selectionSort(int *array, int size);
SortResult insertionSort(int *array, int size);
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
    unsorted.iterations = 0;

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

SortResult bubleSort(int *array, int size)
{
    int *arr = copyArray(array, size);
    int swaps = size;
    int iterations = 0;

    do
    {
        swaps = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
                swaps++;
            }
            iterations++;
        }
    } while (swaps != 0);

    SortResult result;
    result.array = arr;
    result.iterations = iterations;
    return result;
}

SortResult selectionSort(int *array, int size)
{
    int *arr = copyArray(array, size);
    int iterations = 0;
    for (int i = 0; i < size; i++)
    {
        int minIndx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndx])
            {
                minIndx = j;
            }
            iterations++;
        }

        if (minIndx != i)
        {
            swap(arr, i, minIndx);
        }
    }
    SortResult result;
    result.array = arr;
    result.iterations = iterations;
    return result;
}

SortResult insertionSort(int *array, int size)
{
    int *arr = copyArray(array, size);
    int iterations = 0;

    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
        {
            iterations++;
            swap(arr, j, j - 1);
        }
    }

    SortResult result;
    result.array = arr;
    result.iterations = iterations;
    return result;
}

int *fillArray(int size)
{
    int *array = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10000;
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
    fprintf(file, "iterations: %d\n", result.iterations);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d: %d\n", i, result.array[i]);
    }
}

void swap(int *arr, int firtsIndex, int secondIndex)
{
    int tmp = arr[firtsIndex];
    arr[firtsIndex] = arr[secondIndex];
    arr[secondIndex] = tmp;
}
