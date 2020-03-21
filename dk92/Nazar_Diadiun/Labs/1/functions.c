#include "functions.h"
#include <math.h>

void UserInput(int *A, int *B, int *C, int *D)
{
    printf("Enter A: ");
    scanf("%d", &*A);
    printf("Enter B: ");
    scanf("%d", &*B);
    printf("Enter C: ");
    scanf("%d", &*C);
    printf("Enter D: ");
    scanf("%d", &*D);
}

int summof (int from, int to, int number)
{
    int summof = 0;
    if(to >= from)
    {
        while(from <= to)
        {
            summof += pow(number, (from + to));
            from++;
        }
        return summof;
    }
    else
        return -1;
}

void calculate (float A, float B, float C, float D)
{
    if(summof(D, A, 2) != -1 && (100 - B - C) != 0)
    {
    float calculatedValue = ((A + B + C) / (100 - B - C)) + summof(D, A, 2);
        printf("%f\n", calculatedValue);
    }
    else
    {
        printf("Invalid Data!\n");
        return;
    }
}
