#include "tools.h"

double division(int A, int B, int C)
{
	double numerator = (A + B + C);
	double denominator = (100 - B - C);

	return numerator / denominator;
}



double powNum(int base, int exp)
{
	if (exp == 0) return 1;

	double temp = base;
	int i = 1;
	for (; i<exp;i++)
	{
		base *= temp;
	}

	if (exp < 0) return 1 / base;
	else return base;
}

double AlgSum(int A)
{
	double rez = 0;
	int i = 0;
	for (; i <= A; i++)
	{
		rez += powNum(2, A + i);
	}
	return rez;
}
