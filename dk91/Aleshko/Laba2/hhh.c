#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include "hhh.h"

int Create(int *m, int n)
{    FILE * fo;
     fo = fopen("text.txt", "wt");
     for(int i = 0; i < n; i++){
            m[i] = rand() % 1000;
      printf("%d\t", m[i]);
      fprintf(fo, "%d\t", m[i]);
        }printf("\n");
        fclose(fo);
}
void bubbleSort(int *m,  int n)
{
     clock_t time;
     time = clock();
    for(int i = 1; i < n; i++)
    {
        int c = i;
        while(c > 0 and m[c-1] > m[c])
        {
            int b = m[c-1];
            m[c-1] = m[c];
            m[c] = b;
            c -= 1;
        }

    }
    time = clock() - time;
    printf("%f ", (double)time/CLOCKS_PER_SEC);

}
void selectionSort(int *m, int n)
{
  clock_t time;
  time = clock();
  int min, temp;
  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (m[j] < m[min])
        min = j;
    }
    temp = m[i];
    m[i] = m[min];
    m[min] = temp;
  }
   time = clock() - time;
   printf("%f ", (double)time/CLOCKS_PER_SEC);
}
void insertionSort (int *m, int n)
{
    clock_t time;
    time = clock();
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && m[j - 1] > m[j]; j--)
        {
            int temp = m[j];
            m[j] = m[j-1];
            m[j-1] = temp;
        }
    }
    time = clock() - time;
    printf("%f ", (double)time/CLOCKS_PER_SEC);
}
int out(int *m, int n)
{
     for(int i = 0; i < n; i++){
      printf("%d\t", m[i]);
        }
        printf("\n");
}
