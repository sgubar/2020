#include <stdio.h>
#include <stdlib.h>
#include"hhh.h"
#include"ccc.c"
int main ()
{
  float A;
  float B;
  float C;
  float D;
  printf("{A, B, C, D}-Z, A>=0\n");
  scanf("%f %f %f %f", &A, &B, &C, &D);
  printf("%f %f %f %f \n", A, B, C, D);
  if(A<0 || 100-B-C==0)
  {
    printf("error");
    return 0;
  }
   float v1=d(A, B, C);
   float v2=s(A, B, C, D);
   float Q = q(v1, v2);
   printf("%f %f %f",v1, v2, Q);

}
