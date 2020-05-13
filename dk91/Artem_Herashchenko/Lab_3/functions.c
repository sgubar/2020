#include "functions.h"

void ShallSort(char *array, int size)
{
    int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++)
        {
            tmp = array[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < array[j - step])    
                    array[j] = array[j - step];
                else
                    break;
            }
            array[j] = tmp;
        }
}

int linearSearch(char *array, char simvol)
{
    if(array != 0)
    {
        for (int i = 0; i < strlen(array); ++i)
        {
         if(array[i] == simvol)
             return i;
        }
        return -1;
    }
}





