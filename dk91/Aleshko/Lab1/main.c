#include <stdio.h>
#include <stdlib.h>
#include <hidder.h>
int main()
{
    int a, b, c, d = 0;
    scanf("%d %d %d", &a, &b , &c);
    double creck;
    creck = ((a * b)/(b + power(c, 2)))* sum(b, d) ;
    printf(" creck%f", creck);
    return 0;
}
