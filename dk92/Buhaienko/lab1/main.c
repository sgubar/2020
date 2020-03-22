#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CustomMath.h"
#include "Validate.h"

int main()
{
    float B;
    float A;
    float C;
    float b=0;
    float d=0;
    float z=0;

printf("Nikita Buhaienko, DK-92, var 3.\n\n");

printf("enter an decimal integer A>0: ");
scanf("%f", &A);

printf("enter an decimal integer B!=0: ");
scanf("%f", &B);

printf("enter an decimal integer 0<C<=3: ");
scanf("%f", &C);

if(Validate(A,B,C) < 0)
{
    return -1;
}
    else
    {
    d = sigmad(C, A);
    z = A*(sqrt(B+C)/B);
    b = z + d;
    printf("Q = A*(sqrt(B+C)/B)+ sigma(factor(A+D))\n");
    printf("right side of + Q: %f,\n left of + Q equals: %f, Q equals: %f\n", d, z, b);


    }
return 0;
}



