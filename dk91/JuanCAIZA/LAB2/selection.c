#include "selection.h"

SortResult selectionSort(int *array, int size)
{
    int *arr = copyArray(array, size);
    time_t t0 = time(0);
    selection(arr, size);
    time_t t1 = time(0);
    SortResult result;
    result.ellapsedTime = difftime(t1, t0);
    result.array = arr;
    return result;
}
void selection(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndx])
            {
                minIndx = j;
            }
        }

        if (minIndx != i)
        {
            swap(array, i, minIndx);
        }
    }
}
