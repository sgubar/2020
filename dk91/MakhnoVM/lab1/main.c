#include <stdio.h>
#include <stdlib.h>
#include "qwe.h"

int main()
{
    int a, b, c, d = 0;
    printf("Введи 3 числа типа int  A, B, C: ");
    scanf("%d %d %d", &a, &b , &c);
    double win;
    win = (mod(a * c - b)/ power(c, 3))* sum(2, a, d) ;
    printf("Ответ = %f", win);
    return 0;
}


double power(int base, int exp)
{
    int a = base;
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

double mod(int a)
{
    return (a > 0)  ? a : (a * (-1));
}

double sum(int base, int finish, int start)
{
    double a = 0;
    for(; start <= finish; start++)
        {
            a = a  + power(base, start);
        }


        return a;
}
