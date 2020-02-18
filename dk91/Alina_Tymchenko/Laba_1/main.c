#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

double main()
{
  double A, B, C, D;
  char *buff;
  buff = (char*)malloc(sizeof(char) * 128); // char buff[128];

  printf("Print A: \n");
  fgets(buff, 128, stdin);
  A = protect_number(buff, strlen(buff));
  free(buff);

  printf("Print B: \n");
  fgets(buff, 128, stdin);
  B = protect_number(buff, strlen(buff));
  free(buff);

  printf("Print C: \n");
  fgets(buff, 128, stdin);
  C = protect_number(buff, strlen(buff));
  free(buff);

  double result = drob(A, B, C) + Sum(B);
  printf("Q = %lf\n", result);

  return 0;
}

