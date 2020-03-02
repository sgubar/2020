#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
double stepin(int base, int base1, int base2)
{
    int a = base;
    int exp = base1+base2;
    if(exp > 0){

         for(int i = 1; i < exp; i++)
    {
        base *= a;
    }
    return base;
    }else if(exp < 0){
        for(; exp < -1; exp++)
    {
        base *= a;
    }
    return 1.0 / base;
    }else{
        return 1;
    }


}


double sum(int start, int finish)
{
    double a = 0;
    for(; start <= finish; start++)
        {
            a = a  + stepin(2, start, finish);
        }


        return a;
}
