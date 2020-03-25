#include "two.h"
#include <stdio.h>
#include <stdlib.h>

//BUBBLE
void bubbleSort(char arr[], int n)
{
    int j = 0;
for(int i = 0 ; i < n - 1; i++) {
   // сравнение  двух соседних элементов
   for(j = 0 ; j < n - i - 1 ; j++) {
       if (arr[j] > arr[j+1]) {
          
          char tmp = arr[j];
          arr[j] = arr[j+1] ;
          arr[j+1] = tmp;
       }
    }
}
       fprintResult(arr, n);
}


// INSERTION
void insertionSort(char arr[], int n)
    {
      
    int i, j;
        char key;
    for (i = 1; i < n; i++) {
          key = arr[i];
          j = i - 1;
    
      
          while (j >= 0 && arr[j] > key) {
              arr[j + 1] = arr[j];
              j = j - 1;
           }
          arr[j + 1] = key;
      }
         fprintResult(arr, n);
    }

// SELECTION
void selectionSort(char arr[], int n)
{
    
    
    int i, j, min_ind;
  
    
    for (i = 0; i < n-1; i++)
    {
        // минимум
        min_ind = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_ind])
            min_ind = j;
            fprintResult(arr, n);
        
        //минимум первого элемента
        swap (&arr[min_ind], &arr[i]);
 
}
    fprintResult(arr, n);
}

void fprintResult(char array[],  int size) {
    FILE* file = fopen("/Users/marinakshanovskaa/Desktop/THIS/one.c/one.c/result.txt","w");
    fprintf(file,"Result:\n");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%c\n", array[i]);
    }
    fclose(file);
}

//перестановка обьектов
void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
