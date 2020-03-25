#include <time.h>
#include "functions.h"

void bubbleSort(char *array, int size){
clock_t start = clock();
   for (int i = 0; i < size - 1; i++)
  {
    for (int j = (size - 1); j > i; j--)
    {
      if (array[j - 1] < array[j])                  //>
      {
        char temp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = temp;
      }
    }
  }
clock_t end = clock();
printf ("bubble = %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}

void selectionSort(char *array, int size)
{
clock_t start = clock();
  int min;
  char temp;
  for (int i = 0; i < size - 1; i++)
  {
    min = i;

    for (int j = i + 1; j < size; j++)
    {
      if (array[j] > array[min])                //<
        min = j;
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
clock_t end = clock();
printf ("selection = %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}

void inclusionSort(char *array, int size)
{
clock_t start = clock();
  for (int i = 1; i < size; i++)
  {
    char value = array[i];
    int j = i;
    while ((j > 0) && (array[j - 1] < value))     //>
    {
      array[j] = array[j - 1];
      j--;
    }
    array[j] = value;
  }
clock_t end = clock();
printf ("inclusion = %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}
