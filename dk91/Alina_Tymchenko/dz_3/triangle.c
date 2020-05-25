#include "header.h"
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);
void writePointToJSON(FILE *aFile, Point *aPoint);

Triangle *createTriangle(Point *A, Point *B, Point *C)
{
	Triangle *theResult = NULL;

	if (NULL != A && NULL != B && NULL !=C)
	{
	    // выделение памяти под корень списка
		theResult = (Triangle *)malloc(sizeof(Triangle));
		memset(theResult, 0, sizeof(Triangle));
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

Side *copySideBySide(Side *aSide)
{
	Side *theResult = (Side *)malloc(sizeof(Side));

	if (NULL != theResult)
	{
		theResult->x1 = aSide->x1;
		theResult->y1 = aSide->y1;
	}

	return theResult;
}

Triangle *createTriangleThroughSides(Side *AB, Side *AC, Side *BC)
{
	Triangle *aTriangle = (Triangle *)malloc(sizeof(Triangle));
	memset(aTriangle, 0, sizeof(Triangle));
	if (NULL != aTriangle)
	{
		aTriangle->AB = copySideBySide(AB);
		aTriangle->AC = copySideBySide(AC);
		aTriangle->BC = copySideBySide(BC);
		aTriangle->area = AreaTriangle(aTriangle);
	}

	return aTriangle;
}

void destroyTriangle(Triangle *aTriangle)
{
	if (NULL != aTriangle)
	{
		if (NULL != aTriangle->A)
		{
        free(aTriangle->A);
		}
		if (NULL != aTriangle->B)
		{
        free(aTriangle->B);
		}
		if (NULL != aTriangle->C)
		{
			free(aTriangle->C);
		}

		if (NULL != aTriangle->AB)
		{
			free(aTriangle->AB);
		}
		if (NULL != aTriangle->AC)
		{
			free(aTriangle->AC);
		}
		if (NULL != aTriangle->BC)
		{
			free(aTriangle->BC);
		}

		free(aTriangle); // освобождаем память удаляемого узла

	}
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

void printTriangle(Triangle *aTriangle)
{
	if (NULL != aTriangle)
	{
		if (NULL != aTriangle->A && NULL != aTriangle->B && NULL != aTriangle->C)
		{
			printf ("Triangle: Point A(%f,%f), Point B(%f,%f), Point C(%f,%f)\n",
						aTriangle->A->x, aTriangle->A->y,
						aTriangle->B->x, aTriangle->B->y,
						aTriangle->C->x, aTriangle->C->y);
		} else if (NULL != aTriangle->AB && NULL != aTriangle->AC && NULL != aTriangle->BC)
		{
			printf ("Triangle: Side AB(%f,%f), Side AC(%f,%f), Side BC(%f,%f)\n",
						aTriangle->AB->x1, aTriangle->AB->y1,
						aTriangle->AC->x1, aTriangle->AC->y1,
						aTriangle->BC->x1, aTriangle->BC->y1);
		}
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

void writePointToJSON(FILE *aFile, Point *aPoint)
{
    if(NULL == aPoint || NULL == aFile)
    {
        return;
    }
    fprintf(aFile, "{\"x\" : %f, \"y\" : %f}", aPoint->x, aPoint->y);
}

void writeTriangleToJSON(FILE *aFile, Triangle *aTriangle)
{
    if(NULL == aTriangle || NULL == aFile)
    {
        return;
    }
    fprintf(aFile, "{\n\"A\" :");
    writePointToJSON(aFile, aTriangle->A);
    fprintf(aFile, "{\n\"B\" :");
    writePointToJSON(aFile, aTriangle->B);
    fprintf(aFile, "{\n\"C\" :");
    writePointToJSON(aFile, aTriangle->C);
    fprintf(aFile, "\n}");
}
