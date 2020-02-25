#include <stdio.h>
#include <stdlib.h>

#include "dk_math.h"

double Q(int A, int B, int C);

int main(int argc, char *argv[]) 
{
	int A, B, C;
	printf("Write A: ");
	if(scanf("%d", &A) == 0)
	{
		return 1;
	}
	printf("Write B: ");
	if(scanf("%d", &B) == 0)
	{
		return 2;
	}
	printf("Write C: ");
	if(scanf("%d", &C) == 0)
	{
		return 3;
	}
	double r = Q(A, B, C);
	printf("%f \n", r);
	return 0;
}

double Q(int A, int B, int C)
{
	double result;
	if(0 == C)
	{
		return 0;
		printf("C == 0!");
	}
	result = A;
	result *= C;
	result -= B;
	result = mod(result);
	result *= power(C, -3);
	result *= sum(2, 0, A);
	return result;
}
