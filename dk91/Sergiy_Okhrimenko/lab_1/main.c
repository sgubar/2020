#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <math.h>

int main()
{
    int A, B, C, D;

    printf("Enter A: ");
    scanf("%d", &A);
    printf("Enter B: ");
    scanf("%d", &B);
    printf("Enter C: ");
    scanf("%d", &C);
    printf("Enter D: ");
    scanf("%d", &D);

printf("%f\n", A * divide_func(sqrt(B+C), B) + summ(D, C, factorial(A + D)));
}
