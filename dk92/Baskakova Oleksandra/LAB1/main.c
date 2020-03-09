#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "compute.h"

int main(int argc, char const *argv[])
{
    float a, c;
    unsigned int b;

    printf("(A*B)/(B+C^2) + (SUM from D to B (D!))=? (D=0) \n");
    printf("Input three values (A, B, C) or 'e' to exit \n");
    printf("A: \n");
    a = getFloat();
    printf("B (natural number): \n");
    b = getUnsignedInt();
    printf("C: \n");
    c = getFloat();
    printf("Answer: %f\n", compute(a, b, c));
    system("pause");
    return 0;
}

