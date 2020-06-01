#include "insertion.h"

SortResult insertionSort(int *array, int size)
{
     int *arr = copyArray(array, size);
    time_t t0 = time(0);
    insertion (arr, size);
    time_t t1 = time(0);
    SortResult result;
    result.ellapsedTime = difftime(t1, t0);
    result.array = arr;
    return result;
}

void insertion (int *array, int size)
{
   
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
        {
            swap(array, j, j - 1);
        }
    }
}
