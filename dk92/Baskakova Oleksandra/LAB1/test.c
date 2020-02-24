#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float compute(float A, int B, float C);
int factorial(int num);

int main(int argc, char const *argv[])
{
    float a, c;
    int b;
    char ch;

    printf("(A*B)/(B+C^2) + (SUM from D to B (D!))=? (D=0) \n");
    printf("Input three values (A, B, C) : \n");
    int result = 0;
    char *p, s[100];
    printf ("A: \n");
    while (fgets(s, sizeof(s), stdin))
    {
        a = strtof(s, &p);
        if (p == s || *p != '\n')
        {
            printf("Please enter an float: ");
        }
        else
            break;
    }
     printf ("B (natural number): \n");
    while (fgets(s, sizeof(s), stdin))
    {
        b = strtol(s, &p, 10);
        if (p == s || *p != '\n')
        {
            printf("Please enter an integer: \n");
        }
        if (b == 0)
            printf("B should be not equal to zero\n");
        else
            break;
    }
    printf ("C: \n");
    while (fgets(s, sizeof(s), stdin))
    {
        c = strtof(s, &p);
        if (p == s || *p != '\n')
        {
            printf("Please enter an float: ");
        }
        else
            break;
    }
    printf("Answer: %f", compute(a, b, c));
    return 0;
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

float compute(float A, int B, float C)
{
    return ((A * B) / (B * pow(C, 2))) + sum(B);
}
