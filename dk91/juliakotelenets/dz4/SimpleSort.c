#include <stdio.h>
#include <stdlib.h>
#include "SimpleSort.h"


void bubbleSort(int anArray[], int aSize)
{
	for (int theOut = aSize - 1; theOut >= 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
}
