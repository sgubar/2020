1#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    int A = 0, B = 0, Znam = 0, factorial = 0, ModulZnam = 0;
    float result = 0;

    do
    {
        printf("Positive A\n");
        scanf("%i", &A);
    }
    while(0 > A);
    printf("B\n");
    scanf("%i", &B);

    Factorial(A, &factorial);
    Modul(A, B, &ModulZnam, &Znam);
    Result(factorial, &Znam, &ModulZnam, &result);
}
