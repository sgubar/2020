#include <stdio.h>
#include <stdlib.h>

double factor(float x)
{
double fact = 0;
if(x<1){
    return -1;
}
else{
fact = 1;

        for(int i=1; i<=x; i++)
        {
            fact *= i;

        }
}
 return fact;
}


float sigma(float c, float in)
{
    float out = 0;

    for(int d = 0; d<c; d++)
    {
        out = out + in;

    }

return out;
}

float sigmad(float c, float in)
{
    float out = 0;
    long temp;
    for(int d = 0; d<c; d++)
    {
        temp = factor(in + d);
        out = out + temp;

    }

return out;
}
