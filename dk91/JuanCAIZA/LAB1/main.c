#include <stdio.h>
#include <stdlib.h>

double step(int base, int exp);
double sum(int finish, int start);
double fac(int base);
int main()
{
    int a, b, c, d = 0;
    scanf("%d %d %d", &a, &b , &c);
    double qwe;
    qwe = ((a * b)/(b + step(c, 2)))* sum(b, d) ;
    printf(" qwe%f", qwe);
    return 0;
}


double step(int base, int exp)
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
double fac(int in)
{   int out = 1;
if (base>=0){
    for(int i = 1; i<=base; i++)
    {
      out*=i;
    }printf(" fac%d", );
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
  
