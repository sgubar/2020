#include <stdio.h>
#include <stdlib.h>
#include "sortTools.h"

void BubbleSort(int *aArray, int aSize)
{
    int j = aSize-1;
	for(; j > 0; j--)
    {
        int i = 0;
	    for(; i < j; i++)
        {
	        if(aArray[i] > aArray[i+1])
	        {
				swap(&aArray[i], &aArray[i+1]);
			}
        }
    }
}
void SelectionSort(int *aArray, int aSize)
{
    int theOut = 0;
	for(; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut;
		int theIn = theOut + 1;
		for(; theIn < aSize; theIn++)
		{
			if(aArray[theIn] < aArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}
		swap(&aArray[theOut], &aArray[theMinIndex]);
	}
}
void InsertionSort(int *aArray, int aSize)
{
    int theOut = 1;
	for(; theOut < aSize; theOut++)
	{
		int theTmp = aArray[theOut];
		int theIn = theOut;
		while(theIn > 0 && aArray[theIn - 1] >= theTmp)
		{
			aArray[theIn] = aArray[theIn - 1];
			theIn--;
		}
		aArray[theIn] = theTmp;
	}
}
	void swap(int *tmp1, int *tmp2)
{
	int tmp = *tmp1;
	*tmp1 = *tmp2;
	*tmp2 = tmp;
}
