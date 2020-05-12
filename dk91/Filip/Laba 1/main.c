#include <stdio.h>
#include <stdlib.h>
#include "hider.h"

int main()
{
    int a, b, c, d, h = 0;
   do{
   printf("a=");
        scanf("%d", &a);
   }while(a <= 0);
    do{
        printf("b,c=");
        scanf("%d %d", &b, &c);
        h = b + c;
    }while(h == 100);
    double f = a+b+c;
    double g = 100-b-c;
    double rezultat;
    rezultat =  (f / g) + sum(d, a) ;
    printf("%f", rezultat);
}
