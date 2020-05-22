#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char *argv[])
{
  int m1[4][4];
  int m2[4][4];
  int result[4][4];
  int i;
  int j;

  printf("Matrix 1: \n");
  fillmstrix(m1);
  printmatrix(m1);
  printf("\n");

  printf("\nMatrix 2: \n");
  fillmstrix(m2);
  printmatrix(m2);

  i = 0;
  j = 0;

  matrix (m1, m2, result);

  printf("Result: \n");

 for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }


  return 0;
}
