#include "dk_tool.h"
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Ellipse *createEllipse(Point *Centre, int *R, int *r)
{
	Ellipse *theResult = NULL;

	if (NULL != Centre && NULL != R && NULL !=r)
	{
	  
		theResult = (Ellipse *)malloc(sizeof(Ellipse));
		if (NULL != theResult)
		{

			theResult->O = copyPointWithPoint(Centre);
			theResult->R = *R;
			theResult->r = *r;
		}
	}

	return theResult;
}

void destroyEllipse(Ellipse *aEllipse)
{
	if (NULL != aEllipse)
	{
        free(aEllipse->O);
		free(aEllipse); 

	}
}

float SquareEllipse(Ellipse *aEllipse)
{
    float Pi = 3.14159265;
    float theResult = 0.0;

	if (NULL != aEllipse)
	{
		theResult = Pi * aEllipse->R * aEllipse->r;
	}

	return theResult;
}

void printEllipse(Ellipse *aEllipse)
{
	if (NULL != aEllipse)
	{
		printf ("Еліпс: Центр (%d,%d), Основна вісь = %d, Менша вісь = %d\n",
					aEllipse->O->x, aEllipse->O->y,
					aEllipse->R, aEllipse->r);
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
