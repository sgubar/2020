
#include "dk_math.h"

double power(int base, int pow)
{
	int result = 1;
	int _pow = mod(pow);
	
	for (int i = 0; i < _pow; i++)
	{
		result *= base;
	}
	
	return (pow >= 0) ? result : (1.0/result);
}

int mod(int base)
{
	return (base >= 0) ? base : (base * -1);
}

double sum(int base, int start, int finish)
{
	int result = 0;
	
	for (int i = start; i <= finish; i ++)
	{
		result += power(base, i);
	}
	
	return result;
}
