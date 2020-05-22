#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct tagPonit
{
    int x_pos;
    int y_pos;
}Point;

typedef struct tagPrm
{
    Point *A_point;
    Point *B_point;
    Point *C_point;
    Point *D_point;

}Rectg;

Point *createPoint(int x, int y);

Rectg *createRecByParam(int x_a, int y_a, int x_b, int y_b, int x_c, int y_c, int x_d, int y_d);
Rectg *createRecByPoints(Point *pA, Point *pB, Point *pC, Point *pD);

void printRec(Rectg *currRectg);
void deleteRectg(Rectg *currentRec);

void isRecTrue(Point *A, Point *B, Point *C, Point *D);

#endif // RECTANGLE_H_INCLUDED
