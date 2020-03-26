#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fun.h"

void Bubblesort(char array[], int size){
    clock_t start = clock();
    int i , m;
    for(i = 0 ; i < size - 1; i++) {
       for(m = 0 ; m < size - i - 1 ; m++) {

           if(array[m+1] > array[m]) {
            int tmp = array[m+1];
              array[m+1] = array[m] ;
              array[m] = tmp;
}
}
}
    clock_t end = clock();
printf ("bubble = %.100lf\n", (double)(end - start)/CLOCKS_PER_SEC);

 }


 void Selectionsort(char *array, int size)
{
clock_t start = clock();
  int min;
  char temp;
  for (int i = 0; i < size - 1; i++)
  {
    min = i;

    for (int m = i + 1; m < size; m++)
    {

      if (array[m] > array[min])                //<
        min = m;
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
clock_t end = clock();
printf ("selection = %.100lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}

void Insertionsort(char *array, int size)
{
clock_t start = clock();
{
  int key = size;
  int i = 0;
  for(int m = 1; m < size; m++){
    key = array[m];
    i = m - 1;
    while(i >= 0 && array[i]>key){
      array[i + 1] = array[i];
      i = i - 1;
      array[i + 1] = key;
    }
  }
}
clock_t end = clock();
printf ("Insertion = %.100lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}
