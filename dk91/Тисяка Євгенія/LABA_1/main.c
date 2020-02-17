#include <stdio.h>
#include <stdlib.h>
#include"hhh.h"
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
float  d(float A, float B, float C)
{

  if(100-B-C!=0)
  {
    float x=(A+B+C)/(100-B-C);
    return x;
  }
    else
    {

     printf("error:you cannot divide by zero");

  }


}
float s(float A,float B, float C, float D)
{
float s=0;
int i;
int j;
int step;
float x;
  for(i=0; i<=A; i++)
  {

     x=1;
    if((i+D)>=0);
    {
       step=i+D;

      for(j=0; j<step; j++)
      {
        x=x*2;
      }

    }
    if(i+D<0)
    {
       step=-1*(i+D);
      for(j=0; j<step; j++)
      {
        x=x*2;
      }
      x=1/x;
    }
    s=s+x;
  }
  return s;
}
float q(float d, float s)
{
  return d+s;
}
