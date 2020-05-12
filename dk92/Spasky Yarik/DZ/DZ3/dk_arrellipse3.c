#include "dk_ellipse3.h"
#include "dk_arrellipse3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Ellipse *createEllipse(Point *A, Point *B, Point *C, Point *D, Point *Centre)
{
    Ellipse *result = NULL;

    if(A != NULL && B != NULL && C != NULL && D != NULL && Centre != NULL)
    {
       if(abs(A->x) == abs(C->x) && abs(B->y) == abs(D->y) && A->y == C->y && B->x == D->x)
        {
            result = ( Ellipse* )malloc(sizeof(Ellipse));

            if(result != NULL)
            {
                result->A = A;
                result->B = B;
                result->C = C;
                result->D = D;
                result->Centre = Centre;
            }
        }

    }

    return result;
}

void destroyEllipse(Ellipse *eEllipse)
{
    if(eEllipse != NULL)
    {
        free(eEllipse->A);
        free(eEllipse->B);
        free(eEllipse->C);
        free(eEllipse->D);
        free(eEllipse->Centre);
        free(eEllipse);
    }
}

float Ellipse_Area(Ellipse *eEllipse)
{
    float result = 0;

    if(eEllipse != NULL)
    {
        float Part1 = (float)sqrt(pow(eEllipse->C->x - eEllipse->Centre->x, 2)+pow(eEllipse->C->y - eEllipse->Centre->y ,2));
        float Part2 = (float)sqrt(pow(eEllipse->B->x - eEllipse->Centre->x, 2)+pow(eEllipse->B->y - eEllipse->Centre->y ,2));
        result = 3.14*Part1 * Part2;
    }

    return result;
}
Point *copyPointWithPoint(Point *ePoint)
{
    Point *result = (Point *)malloc(sizeof(Point));
    if (NULL != result)
    {
        result->x = ePoint->x;
        result->y = ePoint->y;
    }

    return result;
}

void writePoint(FILE *eFile, Point *ePoint)
{
    if (NULL == ePoint || NULL == eFile)
            return ;


    fprintf(eFile, "{ %d, \"y\" : %d}", ePoint->x, ePoint->y);
}

void writeEllipse(FILE *eFile, Ellipse* eEllipse)
{
    if (NULL == eEllipse|| NULL == eFile)
        return ;


    fprintf(eFile, "{\n\t\"A\" : ");
    writePoint(eFile, eEllipse->A);
    fprintf(eFile, ", \n\t\"B\" : ");
    writePoint(eFile, eEllipse->B);
    fprintf(eFile, ", \n\t\"C\" : ");
    writePoint(eFile, eEllipse->C);
    fprintf(eFile, ", \n\t\"D\" : ");
    writePoint(eFile, eEllipse->D);
    fprintf(eFile, ", \n\t\"Centre\" : ");
    writePoint(eFile, eEllipse->Centre);
    fprintf(eFile, ", \n\t\"Area\" : %f,", Ellipse_Area(eEllipse));

}
