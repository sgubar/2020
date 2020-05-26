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
        printf("The triangle is not rectangular!\n");

    }

    }
    return theResult;
}

int AreaOfRightTriangle(RightTriangle *aTriangle)
{
    int theResult = 0;

    if(aTriangle != NULL)
    {
        int FirstSide = (float)sqrt(pow(aTriangle->B->x - aTriangle->C->x, 2) + pow(aTriangle->B->y - aTriangle->C->y, 2));
        int SecondSide = (float)sqrt(pow(aTriangle->A->x - aTriangle->C->x, 2) + pow(aTriangle->A->y - aTriangle->C->y, 2));




		theResult = (FirstSide * SecondSide) / 2;
    }

    return theResult;
}

void PrintRightTriangle(RightTriangle *aTriangle)
{
	if (NULL != aTriangle)
	{
		printf ("Coordinates of vertices:\nA(%d,%d)\nB(%d,%d)\nC(%d,%d)\n\n",
					aTriangle->A->x, aTriangle->A->y, aTriangle->B->x, aTriangle->B->y,aTriangle->C->x, aTriangle->C->y);
	}
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
