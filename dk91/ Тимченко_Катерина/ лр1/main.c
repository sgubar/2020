#include "hyder.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
float drob(double A, double B, double C)
{
  double result = 0;
  if(C != 0)
  {
    result = (abs(A * C - B)) / (pow(C, 3));
    return result;
  }
  else
    printf("Error\n");
}

int Sum(int A)
{
  int result = 0;
  for(int D = 0; D <= A; D++)
    result += pow(2, D);
  return result;
}

float protect_number (char *buff, int len)
{
  int prot = 0, point = 0, znak = 0;
  float number;
  while(prot != len || znak > 1 || point > 1)
  {
    prot = 1;
    point = 0;
    znak = 0;

    for(int i = 0; i < len; i++)
    {
      if(buff[i] >= '0' && buff[i] <= '9') prot++;
      else if(buff[i] == '.'){point++; prot++;}
      else if(buff[i] == '-'){znak++; prot++;}
    }
    //printf("%d %d\n", prot, len);
        if(prot != len)
    {
      printf("It isn't number! Try again\n");;
      fgets(buff, 128, stdin);
    }
  }
  number = atof(buff);
  return number;
}

  return 0;
}
