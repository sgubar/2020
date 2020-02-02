//
//  dk_line.c
//  dz2
//
//  Created by Slava Gubar on 2/15/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#include "dk_line.h"
#include <stdlib.h>

Point *copyPointWithPoint(Point *aPoint);
void writePointToJSON(FILE *aFile, Point *aPoint);

Line *createLine(Point *A, Point *B)
{
	Line *theResult = NULL;
	
	if (NULL != A && NULL != B)
	{
		theResult = (Line *)malloc(sizeof(Line));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
		}
	}
	
	return theResult;
}

void destroyLine(Line *aLine)
{
	if (NULL != aLine)
	{
		free(aLine->A);
		free(aLine->B);
	
		free(aLine);
	}
}

float lenghLine(Line *aLine)
{
	float theResult = 0.0;
	
	if (NULL != aLine)
	{
		float dX = (aLine->A->x - aLine->B->x);
		float dY = (aLine->A->y - aLine->B->y);
		theResult = sqrt(dX*dX + dY*dY);
	}
	
	return theResult;
}

void printLine(Line *aLine)
{
	if (NULL != aLine)
	{
		printf ("[Line]. A(%d,%d) - B(%d,%d)\n",
					aLine->A->x,aLine->A->y,
					aLine->B->x, aLine->B->y);
	}
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}
	
	return theResult;
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeLineToJSON(FILE *aFile, Line *aLine)
{
	if (NULL == aLine || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aLine->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, aLine->B);
	fprintf(aFile, "\n}");
}

