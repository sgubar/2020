#include "ArrayTools.h"
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

RightTriangle *createRightTriangle(Point *A, Point *B, Point *C)
{
    RightTriangle *theResult = NULL;

    if(A != NULL && B != NULL && C != NULL)
	{
     if(abs(A->y) == abs(C->y) && abs(C->x) == abs(B->x))
        {
            theResult = (RightTriangle* )malloc(sizeof(RightTriangle));

            if(theResult != NULL)
            {
                theResult->A = A;
                theResult->B = B;
                theResult->C = C;
            }
        }
         else
    {
        printf("One of the triangle is not rectangular!\n");

    }

    }
    return theResult;
}

float AreaOfRightTriangle(RightTriangle *aTriangle)
{
    float theResult = 0;

    if(aTriangle != NULL)
    {
        float FirstSide = (float)sqrt(pow(aTriangle->B->x - aTriangle->C->x, 2) + pow(aTriangle->B->y - aTriangle->C->y, 2));
        float SecondSide = (float)sqrt(pow(aTriangle->A->x - aTriangle->C->x, 2) + pow(aTriangle->A->y - aTriangle->C->y, 2));




		theResult = (FirstSide * SecondSide) / 2;
    }

    return theResult;
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

void destroyRightTriangle(RightTriangle *aTriangle)
{
    if(aTriangle != NULL)
    {
        free(aTriangle->A);
        free(aTriangle->B);
        free(aTriangle->C);
        free(aTriangle);
    }
}

void writePointToJSON(FILE *file, Point *aPoint)
{
	if (NULL == aPoint || NULL == file)
	{
		return ;
	}

	fprintf(file, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writetriangleToJSON(FILE *file, RightTriangle *aTriangle)
{
	if (NULL == aTriangle || NULL == file) return ;

	fprintf(file, "{\n\"A\" : ");
	writePointToJSON(file, aTriangle->A);
	fprintf(file, ", \n\"B\" : ");
	writePointToJSON(file, aTriangle->B);
	fprintf(file, ", \n\"C\" : ");
	writePointToJSON(file, aTriangle->C);
	fprintf(file, ", \n\"Area\" :  %.2f", AreaOfRightTriangle(aTriangle));
	fprintf(file, "\n}");
}
