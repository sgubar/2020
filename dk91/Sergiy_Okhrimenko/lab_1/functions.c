
	#include "functions.h"

	int factorial (int value) //works
	{
	    int factorial = 1;
	    int current_position = 1;
	    while (current_position <= value)
	    {
	        factorial *= current_position;
	        current_position += 1;
	    }
	    return factorial;
	}

	    int summ (int from, int to, int value) //from = D, to = B, also works
	    {
	        int summ = 0;
	        while(from <= to)
	        {
	            summ += factorial(value + from);
	            from += 1;
	        }
	        return summ;
	    }

	float divide_func (float first, float second)
	{
	    float divide = 0.00;
	    if(second != 0)
	    {
	        divide = first / second;
	        return divide;
	    }
	    else
	    {
	        printf("Can`t divide by zero!");
	        return -1;
	    }
	}
