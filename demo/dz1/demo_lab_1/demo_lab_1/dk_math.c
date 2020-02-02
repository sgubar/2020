//
//  dk_math.c
//  demo_lab_1
//
//  Created by Slava Gubar on 3/11/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

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

int sum(int base, int finish)
{
	int result = 0;
	
	for (int i = 0; i < finish; i ++)
	{
		result += base;
	}
	
	return result;
}

