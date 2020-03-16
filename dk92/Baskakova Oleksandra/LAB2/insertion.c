#include "insertion.h"

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
