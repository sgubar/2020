#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"



void bubble_sort(char *array, int size)
{
  int k, i;

  for(k = 0; k < size - 1; k++)
  {
      for(i = 0; i < size - 1 - k; i++)
    {
          if(array[i] < array[i + 1])
      {
        char temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;

          }
    }

  }
  fprintResult(array, size,"bubble.txt");
}



void insertion_sort(char *array, int size)
{
    char newElement;
    int  location, i;

    for (i = 1; i < size; i++)
    {
        newElement = array[i];
        location = i - 1;
        while (location >= 0 && array[location] < newElement)
        {
            array[location] = array[location + 1];
            location = location - 1;
        }
        array[location] = newElement;
    }
    fprintResult(array, size,"insertion.txt");
}



void selection_sort(char *array, int size)
{
    char temp;
    int location, i, j;
    for(i = 0; i < size; ++i)
    {
        location = i;
        temp = array[i];
        for(j = i + 1; j < size; ++j)
        {
            if (array[j] > temp)
            {
               location = j;
               temp = array[j];
            }
        }
        array[location] = array[i];
        array[i] = temp;
    }
    fprintResult(array, size,"selection.txt");
}


void fprintResult(char *array,  int size,char fn[20]) {
    FILE* file = fopen(fn,"w");
    fprintf(file,"Result:\n");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%c\n", array[i]);
    }
    fclose(file);
}


void step(char *i, char *j)
{
    char temp = *i;
    *i = *j;
    *j = temp;
}
