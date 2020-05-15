#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hhidk.h"

double fac(int base)
{   int a = 1;
if (base>=0){
    for(int i = 1; i<=base; i++)
    {
       a*=i;
    }
    return a;
    }
    else return 0;
}


double sum(int finish, int start)
{
    int a = 0;
    for(; start <=finish; start++)
        {
            a = a + fac(start);
        }
    return a;
}
