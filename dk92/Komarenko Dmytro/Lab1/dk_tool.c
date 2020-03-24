#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int factorial(int n)
{
    return (n<2)?1:n*factorial(n-1);
}
int module(int n)
{
    return (n<0)?-n:n;
}
int multiplication (int x,int y)
{
    return x*y;
}
double division (double x, double y)
{
        return x/y;
}
int sum (int x,int y)
{
    return x+y;
}
double q(double a, double b)
{
    return division(factorial(a),module(sum(multiplication(2,a),b)));
}

int valid (int a,char d,int c)
{
    int b=0;
    do
    {
        printf("Enter an integer '%c' between %d and %d inclusive:", d, a, c);
        fflush(stdin);
    }while (0==("%d",scanf("%d",&b))||b<a||b>c);
    return b;
}
