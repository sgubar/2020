#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"


void quickSort(char **s_arr, int first, int last)
{
	
    if (first < last)
    {
        int left = first, right = last;
        char* middle = s_arr[(left + right) / 2];
        do
        {
            while (strcmp(s_arr[left], middle) < 0) left++;
            while (strcmp(s_arr[right], middle) > 0) right--;
            if (left <= right)
            {
                char* tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quickSort(s_arr, first, right);
        quickSort(s_arr, left, last);
    }
}