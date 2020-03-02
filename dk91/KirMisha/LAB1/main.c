#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main()
{
    int a, b, c, d = 0;
    scanf("%d %d %d", &a, &b , &c);
    double f = a+b+c;
    double g = 100-b-c;
    double rezultat;
    rezultat =  (f / g) + sum(d, a) ;
    printf("%f", rezultat);
    return 0;
}
