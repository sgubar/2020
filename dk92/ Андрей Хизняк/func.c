#include "func.h"

int factorial (int D)
{
    int factor = 1;
    int current_count = 1;
    while(current_count <= D)
    {
        factor *= current_count;
        current_count++;
    }
    
    return factor;
}

int summ (int B) 
    int summa = 0;
    int D = 0;
    if(D <= B)
    {
    while(D <= B)
    {
        summa += factorial(D);
        D++;
    }
      
        return summa;
    }
    else
    {
        printf("Invalid value!");
        return -1;
    }
}

int square (int number)
{
    int square = number * number;
    return square;
}

float divide (float first, float second)
{
    float divide = 0.00;
    if(second != 0)
    {
        divide = first / second;
    }
    return divide;
}
