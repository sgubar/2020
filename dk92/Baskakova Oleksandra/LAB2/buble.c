#include "buble.h"

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
