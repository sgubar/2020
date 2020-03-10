#include "tool.h"
#include <stdio.h>

int stepen(int chislo)
{
    int result;
        result = chislo * chislo;
    return result;
}

int factorial(int chislo)
{
    int result = 1;
    
    if (chislo < 0)
        {
            printf("factorial can`t be smaller than 0\n");
            return 0;
         }
     
    for (int i = 1; i <= chislo; i++)
        {
            result = result * i;
        }
        return result;
}

int suma(int chislo)
{
    int b = 0;
    int result = 0;
    int c = 0;
    int znamenatel = b + stepen(c);

    if (chislo < 0)
        {
            printf("suma can`t be smaller than 0\n");
            return 0;
        }

    for (b = 0; b <=chislo; b++)
        {
            result = result + factorial(b);
        }
    
   
    if ( znamenatel == 0)
        {
            printf("You have a 0 in your znamenalel\n");
            return 0;
        }
    return result;
    }


int formula(int a, int b, int c)
{
    int result = 0;

    result = ((a*b) / (b + stepen(c))) + suma(b);
    return result;

}

