//
// Created by chelt on 22.04.2020.
//

#include "dk_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);
Point *creatPointFromPoints(Point *fPoint, Point *sPoint);

Figura *createFiguruAndPoints(Point *A, Point *C){
    Figura *theResult = NULL;

    if (NULL != A && NULL != C)
    {
        theResult = (Figura *)malloc(sizeof(Figura));
        if (NULL != theResult)
        {
            theResult->A = copyPointWithPoint(A);
            theResult->C = copyPointWithPoint(C);
            theResult->B = creatPointFromPoints(C, A);
            theResult->D = creatPointFromPoints(A, C);
        }
    }

    return theResult;
}

int sqea(Figura *aFigura){
    float theResult = 0.0;

    if (NULL != aFigura)
    {
        int dX = (aFigura->A->x - aFigura->D->x);
        int dY = (aFigura->A->y - aFigura->B->y);
        theResult = abs(dX)*abs(dY);
    }

    return theResult;
}

void destroyFigura(Figura *aFigura)
{
    if (NULL != aFigura)
    {
        free(aFigura->A);
        free(aFigura->B);
        free(aFigura->C);
        free(aFigura->D);

        free(aFigura);
    }
}

void printFigura(Figura *aFigura)
{
    int l;
    int h;
    if (NULL != aFigura)
    {
        l = abs(aFigura->A->x - aFigura->D->x);
        h = abs(aFigura->A->y - aFigura->B->y);
        printf ("Lengh %d Hight %d\n", l, h);
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

Point *creatPointFromPoints(Point *yPoint, Point *xPoint)
{
    Point *theResult = (Point *)malloc(sizeof(Point));
    if (NULL != theResult)
    {
        theResult->x = xPoint->x;
        theResult->y = yPoint->y;
    }

    return theResult;
}
