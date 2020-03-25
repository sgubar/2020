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
			if (arr[theIn] < arr[theIn + 1]) //меняем местами если стоят не в правильном порядке
			{
				char theTmp = arr[theIn];
				arr[theIn] = arr[theIn + 1];
				arr[theIn + 1] = theTmp;
			}
		}
	}

}





void InsertionSort ( char *arr , int length)
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

void SelectionSort(int length , char *arr)
{
    int theOut;
	for (theOut = 0; theOut < length - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;
		for (theIn = theOut + 1;theIn < length; theIn ++)
		{
			if (arr[theIn]>arr[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		char theTmp = arr[theOut];
		arr[theOut] = arr[theMinIndex];
		arr[theMinIndex] = theTmp;
	}
}

