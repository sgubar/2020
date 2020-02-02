//
//  dk_line_array.c
//  dz3
//
//  Created by Slava Gubar on 3/1/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#include "dk_line_array.h"
#include <stdlib.h>

// init/dealloc
LineArray *createArray(int aNumber)
{
	LineArray *theResult = NULL;
	
	if (aNumber > 0)
	{
		theResult = (LineArray *)malloc(sizeof(LineArray));
	
		if (NULL != theResult)
		{
			theResult->lines = (Line **)malloc(sizeof(Line *)*aNumber);
		
			if (NULL != theResult->lines)
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

void freeArray(LineArray *anArray)
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i ++)
		{
			destroyLine(anArray->lines[i]);
		}
	
		free(anArray->lines);
		free(anArray);
	}
}

//interface
//returns index of added element OR -1 if fail
int addElement(LineArray *anArray, Line *aLine)
{
	int theResult = -1;
	
	if (NULL != anArray && NULL != aLine &&
				anArray->count < anArray->number)
	{
		anArray->lines[anArray->count] =
					createLine(aLine->A, aLine->B);
	
		theResult = anArray->count;
		anArray->count ++;
	}
	
	return theResult;
}

void writeArrayToJSON(FILE *aFile, LineArray *anArray)
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
		writeLineToJSON(aFile, anArray->lines[i]);
	
		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}
	
	fprintf(aFile, "]\n}");
}

void printArray(LineArray *anArray)
{
	if (NULL == anArray)
	{
		return;
	}

	printf("[LA]: number(%d), count(%d)", anArray->number, anArray->count);
	printf(", lines: \n");
	
	for (int i = 0; i < anArray->count; i ++)
	{
		printLine(anArray->lines[i]);
	}
}

void sort_simple(LineArray *anArray)
{
	if (NULL == anArray || anArray->count == 0)
	{
		return ;
	}

	for (int theOut = anArray->count - 1; theOut > 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
//			if (anArray[theIn] > anArray[theIn + 1])
			if (lenghLine(anArray->lines[theIn]) > lenghLine(anArray->lines[theIn + 1]))
			{
//				int theTmp = anArray[theIn];
//				anArray[theIn] = anArray[theIn + 1];
//				anArray[theIn + 1] = theTmp;

				Line *theTmp = anArray->lines[theIn];
				anArray->lines[theIn] = anArray->lines[theIn + 1];
				anArray->lines[theIn + 1] = theTmp;
			}
		}
	}
}

void sort_select(LineArray *anArray)
{
	if (NULL == anArray || 0 == anArray->count)
	{
		return ;
	}
	
//	for (int theOut = 0; theOut < aSize - 1; theOut ++)
	for (int theOut = 0; theOut < anArray->count - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
//		for (int theIn = theOut + 1; theIn < aSize; theIn ++)
		for (int theIn = theOut + 1; theIn < anArray->count; theIn ++)
		{
//			if (anArray[theIn] < anArray[theMinIndex])
			if (lenghLine(anArray->lines[theIn]) < lenghLine(anArray->lines[theMinIndex]))
			{
				theMinIndex = theIn;
			}
		}
	
//		int theTmp = anArray[theOut];
//		anArray[theOut] = anArray[theMinIndex];
//		anArray[theMinIndex] = theTmp;
		Line *theTmp = anArray->lines[theOut];
		anArray->lines[theOut] = anArray->lines[theMinIndex];
		anArray->lines[theMinIndex] = theTmp;
	}
}
