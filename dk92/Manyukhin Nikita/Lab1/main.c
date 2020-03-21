#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
int main()
{
int A, B, C;

    printf("Enter num A: ");
    scanf("%d", &A);

    printf("Enter num B: ");
    scanf("%d", &B);

    printf("Enter num C: ");
    scanf("%d", &C);


    if(B+C == 100)
    {
        printf("ERROR, YOUR DENOMINATOR = 0");
    }
    else
    {
        double sum = AlgSum(A);
        double segmentation = division(A, B, C);
        double result = sum + segmentation;
        printf("Result = %1.3f", result);
    }

    return 0;
}
