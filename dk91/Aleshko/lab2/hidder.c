#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include "hidder.h"

int Create(int m[5], int n)
{
     for(int i = 0; i < n; i++){
            m[i] = rand() % 1000;
      printf("%d\t", m[i]);
        }printf("\n");
}
int array_sort(int m[5], int n)
{
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
}
int out(int m[5], int n)
{
     FILE * fo;
     fo = fopen("text.txt", "a");
     for(int i = 0; i < n; i++){
      printf("%d\t", m[i]);
      fprintf(fo, "%d\t", m[i]);
        }
      fclose(fo);
}
