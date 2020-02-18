#include <stdio.h>
#include <stdlib.h>

#include "dk_matool.h"

int main() {
    float A, B, C;

    printf("Enter num A: ");
    scanf("%f", &A);
    printf("Enter num B: ");
    scanf("%f", &B);
    printf("Enter num C: ");
    scanf("%f", &C);

    if (C == 0)
    {
        printf("ERROR YOUR C = 0");
        
    }
    else
    {
        double rezult = 0;
        double chsl = modNum(A * C - B);
        double znmnk = powNum(C, 3);

        rezult += chsl / znmnk;
        rezult += algSum(A);

        printf("YOUR REZULT: %.3f", rezult);
 
   }
   return 0;
}
