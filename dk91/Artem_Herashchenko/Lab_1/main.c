#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

int main()
{
    int A,B,C;
    float Q;

    printf("Enter A: ");
    scanf("%d", &A);

    printf("Enter B: ");
    scanf("%d", &B);

    printf("Enter C: ");
    scanf("%d", &C);

    if(B==0){
        printf("ERROR: Cannot be divided by zero");
    }else if(C<0){
        printf("ERROR: Enter non-negative C");
    }else{
        Q = A*sqrt(B+C)/B+sum(C, A);

       //printf("sqrt = %f\n", sqrt(B+C));

       //printf("factorial= %d\n", factorial(A));

       //printf("sum= %.2f\n", sum(C, A));

       printf("Q = %.2f\n ", Q);
       }
    return 0;
}
