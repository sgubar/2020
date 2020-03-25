#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Sort.h"
// Defining comparator function as per the requirement
int cmp( const void *a, const void *b) {
    return -(*(char*)a - *(char*)b );
}

void sort( char* str, int size ) {
  clock_t start = clock();
    qsort(str, size, sizeof(char), cmp);
    clock_t end = clock();
printf ("selection = %.100lf\n", (double)( end - start)/CLOCKS_PER_SEC);
}

void sort1(char a[], int n){
    clock_t start = clock();
    int i , j;
    for(i = 0 ; i < n - 1; i++) {
       // сравниваем два соседних элемента.
       for(j = 0 ; j < n - i - 1 ; j++) {
           if(a[j+1] > a[j]) {
              // если они идут в неправильном порядке, то
              //  меняем их местами.
              int tmp = a[j+1];
              a[j+1] = a[j] ;
              a[j] = tmp;
           }
        }
    }
    clock_t end = clock();
printf ("selection = %.100lf\n", (double)(end - start)/CLOCKS_PER_SEC);

 }


 void sort2 (char *a, int size)
{
clock_t start = clock();
  int min;
  char temp;
  for (int i = 0; i < size - 1; i++)
  {
    min = i;

    for (int j = i + 1; j < size; j++)
    {
      if (a[j] > a[min])                //<
        min = j;
    }
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
  }
clock_t end = clock();
printf ("selection = %.100lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}




void sort3(char *a, int size)
{
clock_t start = clock();
  for (int i = 1; i < size; i++)
  {
    char value = a[i];
    int j = i;
    while ((j-1 > 0) && (a[j ] < value))     //>
    {
      a[j-1] = a[j ];
      j--;
    }
    a[j] = value;
  }
clock_t end = clock();
printf ("inclusion = %.100lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}
