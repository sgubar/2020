#include <math.h>
#include "compute.h"

float compute(float A, int B, float C)
{
    return ((A * B) / (B * pow(C, 2))) + sum(B);
}

int factorial(int num)
{
    return num <= 1 ? num : num * factorial(num - 1);
}

int sum(int limit)
{
    int result = 0;
    for (int d = 0; d <= limit; d++)
    {
        result += factorial(d);
    }
    return result;
}