#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int pow1(int B)
{
	if (! B)
	{
		return 1;
	}
	
	int T = 16;
	
	for(int i = 1; i < B; i++)
	{
		T *= 16;
	}

	return T;
}


float sixth(char* F)
{
	int size = 0;
	
	for (int i = 0; *(F+i); ++i)size++;

	int length2 = size;

	float result2 = 0;

	for(int length = 0; length < length2; length++)
	{

		int A = atoi(F+length);
		
		if(! A)
		{
			switch(toupper(*(F+length)))
			{
				default: 
					A = 0;
					break;
				case 'A':
					A = 10;
					break;
				case 'B':
					A = 11;
					break;
				case 'C':
					A = 12;
					break;
				case 'D':
					A = 13;
					break;
				case 'E':
					A = 14;
					break;
				case 'F':
					A = 15;
					break;
			}
		}
		
		result2 += (pow1(size-length-1)*A);
	}

	return result2;
}


float sum(float D)
{
	return ((D*(D+1))/2);	 
}

