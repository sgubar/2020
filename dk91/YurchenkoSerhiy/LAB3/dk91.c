#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>
#include "dk91.h"

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
int out(int *m, int n)
{
     for(int i = 0; i < n; i++){
      printf("%d\t", m[i]);
        }
        printf("\n");
}
void quicksort(int *m,  int first, int last)
{
        if (first < last)
    {
        int left = first, right = last, middle = m[(left + right) / 2];
        do
        {
            while (m[left] < middle) left++;
            while (m[right] > middle) right--;
            if (left <= right)
            {
                int tmp = m[left];
                m[left] = m[right];
                m[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quicksort(m, first, right);
        quicksort(m, left, last);
    }
}
int poisk(int *m, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (m[i] == key)
        return i;
    }
    return -1;
}
