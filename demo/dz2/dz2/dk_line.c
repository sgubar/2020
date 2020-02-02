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
Point *creatPointWithCoordinate(int x, int y);

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

Line *createLineWithCoordinate(int xA, int yA, int xB, int yB)
{
	Line *theResult = (Line *)malloc(sizeof(Line));
	
	if (NULL != theResult)
	{
		theResult->A = creatPointWithCoordinate(xA, yA);
		theResult->B = creatPointWithCoordinate(xB, yB);
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

Point *creatPointWithCoordinate(int x, int y)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = x;
		theResult->y = y;
	}
	
	return theResult;
}
