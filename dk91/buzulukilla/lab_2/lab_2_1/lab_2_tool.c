#include "lab_2_tool.h"

int randomization (int A)
{
	srand(A);
	
	int random=rand()%10000;
	
	return random;
}
