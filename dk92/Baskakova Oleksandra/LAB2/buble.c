#include "buble.h"

SortResult bubleSort(int *array, int size)
{
    int *arr = copyArray(array, size);
    int swaps = size;
    int iterations = 0;
    time_t t0 = time(0);

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
    time_t t1 = time(0);

    SortResult result;
    result.ellapsedTime = difftime(t1,t0);
    result.array = arr;
    return result;
}