#include "dk_tool.h"
#include "stdio.h"

void Factorial(int A, int *factorial)
{
    *factorial = 1;
    for(int i = 2; i <= A; i++)
    {
        *factorial *= i;
    }
    printf("Factorial: %i\n", *factorial);
}

void Modul(int A, int B, int *Znam, int *ModulZnam)
{

    *Znam = 2 * A + B;

    if(0 > *Znam)
    {
        *ModulZnam = *Znam * (-1);
    }
    else
    {
        *ModulZnam = *Znam;
    }
      printf("Modul:%i\n", *ModulZnam);
}

void Result(int factorial, int *Znam, int *ModulZnam, float *result)
{

    if(*Znam != 0)
    {
        *result = (float)factorial / *ModulZnam;
        printf("Result %.3f\n", *result);
    }
    else
        printf("Error (Znamenatel = 0)");
}
