#include <stdio.h>
#include "functions.h"

int main()
{
    int A, B, C, D;
    
    UserInput(&A, &B, &C, &D);
    
    calculate(A, B, C, D);
}
