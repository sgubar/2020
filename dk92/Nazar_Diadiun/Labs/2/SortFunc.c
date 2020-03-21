//
//  SortFunc.c
//  Laboratory work 2
//
//  Created by Nazar Diadiun on 10.03.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include "SortFunc.h"
#include <stdlib.h>
#include<stdio.h>

long getCharacterCount()
{
    FILE *in_file;
    in_file=fopen("/Users/nazar/Desktop/Labs/Laboratory work 2/input.txt","r");
    long count = 0;
    int c;
    while((c=fgetc(in_file)))
    {
      if(c == EOF) break;
      count+=1;
    }
    count -= 1;
    
    fclose(in_file);
    return count;
}

char* fileprocess(long ArraySize)
{
    FILE *in_file;
    in_file=fopen("/Users/nazar/Desktop/Labs/Laboratory work 2/input.txt","r");
    
    char* a = ( char* ) calloc( ArraySize, sizeof(char) );
    int i;
    for ( i = 0; i < ArraySize; ++i )
           a[ i ] = ( char ) calloc( ArraySize, sizeof(char) );
        
    for(int i = 0; i < ArraySize; i++)
        fscanf(in_file, "%s", &a[i]);
    
    fclose(in_file);
    return a;
}

void bubbleSort (char* matrix, long N)
{
    char temp;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N-1; j++)
        {
            if(matrix[j+1] < matrix[j])
            {
                temp = matrix[j];
                matrix[j] = matrix[j+1];
                matrix[j+1] = temp;
            }
        }
    fileWrite(matrix);
}

void insertionSort(char* matrix, long N)
{
    int flag = 0, t, d;
    for (int c = 1 ; c <= N - 1; c++)
    {
      t = matrix[c];

      for (d = c - 1 ; d >= 0; d--)
      {
        if (matrix[d] > t)
        {
          matrix[d+1] = matrix[d];
          flag = 1;
        }
        else
          break;
      }
      if (flag)
        matrix[d+1] = t;
    }
    fileWrite(matrix);
}

void selectionSort(char* matrix, long N)
{
    int position = 0 ,t;
    for (int c = 0; c < (N - 1); c++)
    {
      position = c;

      for (int d = c + 1; d < N; d++)
      {
        if (matrix[position] > matrix[d])
          position = d;
      }
      if (position != c)
      {
        t = matrix[c];
        matrix[c] = matrix[position];
        matrix[position] = t;
      }
    }
    
    fileWrite(matrix);
}

void fileWrite (char* matrix)
{
    FILE  *out_file;
    out_file=fopen("/Users/nazar/Desktop/Labs/Laboratory work 2/output.txt","w");
    

    fprintf(out_file, "%s ",matrix);
    
    fclose(out_file);
}
