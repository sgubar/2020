#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void matrix (int m1[][4], int m2[][4], int result[][4])
{
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        result[i][j] = m1[i][j] - m2[i][j];
      }
      printf("\n");
    }
}

void fillmstrix(int m1[][4]){

    for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
        m1[i][j] = rand() % 100 + 1;
    }
  }
}

void printmatrix(int m1[][4]){
for (int i =0; i < 4; i++)
  {
    for (int j =0; j < 4; j++)
    {
      printf("%d ", m1[i][j]);
    }
    printf("\n");
  }
}
