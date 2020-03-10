#include <stdio.h>
#include "func.h"

int main()
{
    
    int A, B, C, D=0;
    
    printf("Enter A: ");
    scanf("%d", &A);
    printf("Enter B: ");
    scanf("%d", &B);
    printf("Enter C: ");
    scanf("%d", &C);
    
    
    float result = divide((A * B), (B + square(C))) + summ(B);
    
    printf("%f\n", result);
}
