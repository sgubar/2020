#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
