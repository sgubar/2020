#include <stdio.h>
#include <stdlib.h>
#include"DK91.h"
#include"DK91.c"
int main ()
{
  float A, B, C, D;
  printf("Enter the value of variable A(A is a natural number and greater than zero):");
  A =inputVariables(A);
   printf("A=%f\n", A);
  printf("Enter the value of variable B(B is a natural number):");
  B =inputVariables(B);
   printf("B=%f\n", B);
   printf("Enter the value of variable C(C is a natural number):");
  C =inputVariables(C);
   printf("C=%f\n", C);
   printf("Enter the value of variable D(D is a natural number):");
  D =inputVariables(D);
   printf("D=%f\n", D);

  if(A<0 || 100-B-C==0)
  {
    printf("error");
    return 0;
  }
   float v1=d(A, B, C);
   float v2=s(A, B, C, D);
   float Q = q(v1, v2);
  printf("v1=%f\nv2=%f\nQ=%f",v1, v2, Q);

}
