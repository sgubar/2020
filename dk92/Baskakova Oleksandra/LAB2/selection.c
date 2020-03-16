#include "selection.h"

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