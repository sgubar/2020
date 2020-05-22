#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include <stdio.h>

typedef struct tagPonit
{
    int x;
    int y;
}Point;

typedef struct tagRectg
{
    Point *A;
    Point *B;
    Point *C;
    Point *D;

}Rectg;

Rectg *createRec(Point *A, Point *B, Point *C, Point *D);
Rectg *createRecByParam(int x_a, int y_a, int x_b, int y_b, int x_c, int y_c, int x_d, int y_d);
Rectg *createRecByPoints(Point *pA, Point *pB, Point *pC, Point *pD);
void isRecTrue(Point *A, Point *B, Point *C, Point *D);

void deleteRectg(Rectg *currRectg);

int lenSide(Point *A, Point *B);
float areaOfRec(Rectg *currRectg);
void printRec(Rectg *currRectg);

void writePointToJSON(FILE *aFile, Point *aPonit);
void writeRecToJSON(FILE *aFile, Rectg *currRectg);


#endif // RECTANGLE_H_INCLUDED
