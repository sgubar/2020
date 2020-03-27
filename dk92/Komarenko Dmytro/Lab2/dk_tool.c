#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"


void BubbleSort (char *arr , int length)
{
    int theOut;
	for (theOut = length; theOut > 1; theOut --)
	{
		int theIn;
		for (theIn = 0; theIn < theOut ; theIn ++)
		{
			if (arr[theIn] < arr[theIn + 1])
			{
				char theTmp = arr[theIn];
				arr[theIn] = arr[theIn + 1];
				arr[theIn + 1] = theTmp;
			}
		}
	}

}


void SelectionSort(char *arr ,int length )
{
    int theOut;
	for (theOut = 0; theOut < length - 1; theOut ++)
	{
		int theMaxIndex = theOut;
		int theIn;
		for (theIn = theOut + 1;theIn < length; theIn ++)
		{
			if (arr[theIn]>arr[theMaxIndex])
			{
				theMaxIndex = theIn;
			}
		}

		char theTmp = arr[theOut];
		arr[theOut] = arr[theMaxIndex];
		arr[theMaxIndex] = theTmp;
	}
}


void InsertionSort (char *arr ,int length)
{
    int theOut;

	for (theOut = 1; theOut < length; theOut ++)
	{
		char theTmp = arr[theOut];
		int theIn = theOut;
		while (theIn > 0 && (arr[theIn-1] <= theTmp))
		{
			arr[theIn] = arr[theIn - 1];
			-- theIn;
		}
			arr[theIn] = theTmp;
	}
}
