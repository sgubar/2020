#include "buble.h"

SortResult bubleSort(int *array, int size)
{
    int *arr = copyArray(array, size);

    time_t t0 = time(0);
    buble(arr, size);
    time_t t1 = time(0);

    SortResult result;
    result.ellapsedTime = difftime(t1, t0);
    result.array = arr;
    return result;
}

void buble(int *array, int size)
{
    int swaps;
    do
    {
        swaps = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array, i, i + 1);
                swaps++;
            }
        }
    } while (swaps != 0);
}
