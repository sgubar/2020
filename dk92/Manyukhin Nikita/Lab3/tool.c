#include <stdlib.h>
#include <stdio.h>
#include "tool.h"



void ArrayFilling (int *Array, int aSize)
{
    srand(time(NULL));
    for (int i = 0; i < aSize; i++)
    {
        Array[i] = rand()%10000;
    }
}


void swap (int *tmp1, int *tmp2)
{
    int tmp = *tmp1;
	*tmp1 = *tmp2;
	*tmp2 = tmp;

}

void QuickSort(int Array[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(Array[i]<=Array[pivot]&&i<last)
            i++;
         while(Array[j]>Array[pivot])
            j--;
         if(i<j) swap (&Array[i], &Array[j]);
      }

      swap (&Array[pivot], &Array[j]);
      QuickSort(Array,first,j-1);
      QuickSort(Array,j+1,last);

   }
}

void printArrayToFile(int Array[], int aSize, char* name)
{
    FILE*file = fopen (name , "w");
    for (int i = 0; i < aSize; i++)
    {
        fprintf(file, "%d ", Array[i]);
    }
}

void LinearSearch (int Array[], int aKey, int aSize)
{
    FILE * file = fopen ("aKey Result.txt", "w");
    fprintf(file, "You were looking for a number %d, address of this number:\n", aKey);
    int i;
    for (i = 0; i < aSize; i++)
    {
        if (Array[i] == aKey)
        {
            fprintf(file, "Array[%d]\n", i);
        }
    }
}

