
#ifndef DK_ELLIPSE3_H
#define DK_ELLIPSE3_H


#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagEllipse
{
    Point *A;
    Point *B;
    Point *C;
    Point *D;
    Point *Centre;
}Ellipse;

Ellipse *createEllipse(Point *A, Point *B, Point *C, Point *D, Point *Centre);
void destroyEllipse(Ellipse *eEllipse);
void writeEllipse(FILE *eFile, Ellipse *eEllipse);
float Ellipse_Area(Ellipse *eEllipse);
Point *copyPointWithPoint(Point *ePoint);


#endif

