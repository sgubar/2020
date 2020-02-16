#include "header.h"

double main(int argc, char const *argv[])
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

  printf("Print D: \n");
  fgets(buff, 128, stdin);
  D = protect_number(buff, strlen(buff));
  free(buff);
  
  double result = drob(A, B, C) * Sum(A);
  printf("Your result is: %0.2lf\n", result);


  return 0;
}
