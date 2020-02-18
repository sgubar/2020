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
    }else{
        Q = A*sqrt(B+C)/B+sum(C, A);
       printf("%.3f ", Q);
       }
    return 0;
}
