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
double fac(int base)
{   int a = 1;
if (base>=0){
    for(int i = 1; i<=base; i++)
    {
      a*=i;
    }printf(" fac%d", a);
    return a;
           }else return 0;
}


double sum(int finish, int start)
{
    int a = 0;
    for(; start <=finish; start++)
        {
            a = a + fac(start);
            printf(" sum%d", a);
        }
        printf(" sume%d", a);
        return a;
}
