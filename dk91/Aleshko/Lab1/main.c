#include <stdio.h>
#include <stdlib.h>
#include <hidder.h>
int main()
{
    int a, b, c, d = 0;
        printf("a=");
        scanf("%d", &a);
    do{
        printf("b=");
        scanf("%d", &b);
    }while(b<=0);
    do{
        printf("c=");
        scanf("%d", &c);
    }while(c<=0);
    double creck;
    int f = a*b;
    int g = b + power(c, 2);
    creck = (f/g)+sum(b, d) ;
    printf(" creck%f", creck);
    return 0;
}
