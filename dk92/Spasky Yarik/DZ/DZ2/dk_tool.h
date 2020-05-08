#ifndef dk_tool
#define dk_tool
#include <stdio.h>
#include <math.h>
#include <malloc.h>


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

int Ellipse_Area(Ellipse *eEllipse);

#endif

