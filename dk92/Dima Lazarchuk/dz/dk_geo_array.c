#include "dk_geo_array.h"
#include <stdlib.h>

// init/dealloc
RectangleArray *createArray(int aNumber)
{
	RectangleArray *theResult = NULL;
	
	if (aNumber > 0)
	{
		theResult = (RectangleArray *)malloc(sizeof(RectangleArray));
	
		if (NULL != theResult)
		{
			theResult->items = (Rectangle **)malloc(sizeof(Rectangle *)*aNumber);
		
			if (NULL != theResult->items)
			{
				theResult->number = aNumber;
				theResult->count = 0;
			}
			else
			{
				free(theResult);
				theResult = NULL;
			}
		}
	}
	
	return theResult;
}

void freeArray(RectangleArray *anArray)
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i ++)
		{
			destroyRectangle(anArray->items[i]);
		}
	
		free(anArray->items);
		free(anArray);
	}
}

//interface
//returns index of added element OR -1 if fail
int addElement(RectangleArray *anArray, Rectangle *aRectangle)
{
	int theResult = -1;
	
	if (NULL != anArray && NULL != aRectangle &&
				anArray->count < anArray->number)
	{
		anArray->items[anArray->count] =
					createRectangle(aRectangle->A, aRectangle->B, aRectangle->C, aRectangle->D);
	
		theResult = anArray->count;
		anArray->count ++;
	}
	
	return theResult;
}

void writeArrayToJSON(FILE *aFile, RectangleArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"lines\" : \n[\n");
	
	for (int i = 0; i < anArray->count; i ++)
	{
		writeeRectangleToJSON(aFile, anArray->items[i]);
	
		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}
	
	fprintf(aFile, "]\n}");
}

void printArray(RectangleArray *anArray)
{
	if (NULL == anArray)
	{
		return;
	}

	printf("[RA]: number(%d), count(%d)", anArray->number, anArray->count);
	printf(", items: \n");
	
	for (int i = 0; i < anArray->count; i ++)
	{
		printRectangle(anArray->items[i]);
	}
}

void sort_simple(RectangleArray *anArray)
{
	if (NULL == anArray || anArray->count == 0)
	{
		return ;
	}

	for (int theOut = anArray->count - 1; theOut > 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
			if (Compare(anArray->items[theIn], anArray->items[theIn + 1]) > 0)
			{
				swap(theIn, theIn + 1, anArray);
			}
		}
	}
}

void sort_select(RectangleArray *anArray)
{
	if (NULL == anArray || 0 == anArray->count)
	{
		return ;
	}
	
	for (int theOut = 0; theOut < anArray->count - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (int theIn = theOut + 1; theIn < anArray->count; theIn ++)
		{
			if (Compare(anArray->items[theIn], anArray->items[theMinIndex]) < 0)
			{
				theMinIndex = theIn;
			}
		}
		swap(theOut, theMinIndex, anArray);
	}
}

void insertionSort(RectangleArray *anArray)
{
	if (NULL == anArray || 0 == anArray->count)
	{
		return;
	}
	for (int theOut = 1; theOut < anArray->count; theOut ++)
	{
		Rectangle *theTmp = anArray->items[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && Compare(anArray->items[theIn - 1], theTmp) >= 0)
		{
			anArray->items[theIn] = anArray->items[theIn - 1];
			--theIn;
		}
	
		anArray->items[theIn] = theTmp;
	}
}

void swap(int a, int b, RectangleArray *anArray)
{
	Rectangle *theTmp = anArray->items[a];
	anArray->items[a] = anArray->items[b];
	anArray->items[b] = theTmp;
}

int Compare(Rectangle *a, Rectangle *b)
{
	if(NULL == a || NULL == b)
		return -2;
	if(areaRectangle(a) >= areaRectangle(b))
	{
		return areaRectangle(a) == areaRectangle(b) ? 0 : 1;
	}
	return -1;
}

