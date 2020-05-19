#include "header.h"
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Triangle *createTriangle(Point *A, Point *B, Point *C)
{
	Triangle *theResult = NULL;

	if (NULL != A && NULL != B && NULL !=C)
	{
	    // выделение памяти под корень списка
		theResult = (Triangle *)malloc(sizeof(Triangle));
		if (NULL != theResult)
		{
		    // Присваивание значения узлу
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
		}
	}

	return theResult;
}
Side *createSide(Point *A, Point *B)
{
	Side *aSide = (Side *)malloc(sizeof(Side));

	if (NULL != aSide)
	{
		aSide->x1 = abs(B->x - A->x);
		aSide->y1 = abs(B->y - A->y);
	}

	return aSide;
}
Triangle *createTriangleThroughSides(Side *AB, Side *AC, Side *BC)
{
	Triangle *aTriangle = (Triangle *)malloc(sizeof(Triangle));
	if (NULL != aTriangle)
	{
		aTriangle->AB = AB;
		aTriangle->AC = AC;
		aTriangle->BC = BC;
		aTriangle->area = AreaTriangle(aTriangle);
	}

	return aTriangle;
}
float AreaTriangle(Triangle *aTriangle)
{
    float area = 0;

	if (NULL != aTriangle)
	{
		float Len_AB = sqrt(aTriangle->AB->x1*aTriangle->AB->x1 + aTriangle->AB->y1*aTriangle->AB->y1);
		float Len_AC = sqrt(aTriangle->AC->x1*aTriangle->AC->x1 + aTriangle->AC->y1*aTriangle->AC->y1);
		float Len_BC = sqrt(aTriangle->BC->x1*aTriangle->BC->x1 + aTriangle->BC->y1*aTriangle->BC->y1);
		float p=(Len_AB+Len_AC+Len_BC)/2;

		area = sqrt(p*(p-Len_AB)*(p-Len_BC)*(p-Len_AC));
	}

	return area;
}
void printPoint(Point *aPoint)
{
	if (NULL != aPoint)
	{
		printf("Point [%.1f, %.1f]\n", aPoint->x, aPoint->y);
	}
}

void destroyTriangle(Triangle *aTriangle)
{
	if (NULL != aTriangle)
	{
        free(aTriangle->A);
        free(aTriangle->B);
        free(aTriangle->C);
		free(aTriangle); // освобождаем память удаляемого узла

	}
}


void printTriangle(Triangle *aTriangle)
{
	if (NULL != aTriangle)
	{
		printf ("Triangle: Point A(%d,%d), Point B(%d,%d), Point C(%d,%d)\n",
					aTriangle->A->x, aTriangle->A->y,
					aTriangle->B->x, aTriangle->B->y,
					aTriangle->C->x, aTriangle->C->y);
	}
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
	    // Присваивание указателю theResult->x значения указателя aPoint -> х
        // (созданный новый узел)
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}

	return theResult;
}
