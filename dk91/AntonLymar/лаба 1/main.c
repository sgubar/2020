#include <stdio.h>
#include <stdlib.h>
#include "hhidk.h"
int main()
{
    int a, b, c, d = 0;
        printf("a=");
        scanf("%d", &a);
    do{
        printf("b=");
        scanf("%d", &b);
    }
    while(b<=0);
    do{
        printf("c=");
        scanf("%d", &c);
    }
    while(c<=0);
    double fix;
    int w = a*b;
    int k = b + (c*c);
    fix = (w/k)+sum(b, d) ;
    printf(" fix%f", fix);
}
