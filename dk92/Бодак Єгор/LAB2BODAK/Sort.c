#include "sort.h"

char *bubbleSort(char *array, int sizeOfArray)
{
    if (array != NULL)
    {
        char tmp;
        for (int i = 0; i < sizeOfArray - 1; i++)
        {
            for (int j = 0; j < sizeOfArray - i - 1; j++)
            {
                if ((int)array[j] > (int)array[j + 1])
                {
                    tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }

        return array;
    }
}

char *chooseSort(char *array, int size)
{
    if (array != NULL)
    {
        for (int i = 0; i < size - 1; i++)
        {
            int min_i = i;
            for (int j = i + 1; j < size; j++)
            {
                if ((int)array[j] < (int)array[min_i])
                {
                    min_i = j;
                }
            }

            char temp = array[i];
            array[i] = array[min_i];
            array[min_i] = temp;
        }
    }

    return array;
}

char *pasteSort(char *array, int size)
{
    if (array != NULL)
    {
        char newElement;
        int location;

        for (int i = 1; i < size; i++)
        {
            newElement = array[i];
            location = i - 1;
            while(location >= 0 && (int)array[location] > (int)newElement)
            {
                array[location+1] = array[location];
                location = location - 1;
            }
            array[location+1] = newElement;
        }
    }

    return array;
}
