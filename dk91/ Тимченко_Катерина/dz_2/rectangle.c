#include <math.h>
#include "rectangle.h"

Point *createPoint(int x, int y)
{
    Point *rezult = (Point *)malloc(sizeof(Point));
    if (rezult != NULL)
    {
        rezult->x_pos = x;
        rezult->y_pos = y;
    }

    return rezult;

}

void isRecTrue(Point *A, Point *B, Point *C, Point *D)
{
    if (A->y_pos != B->y_pos)
    {
        B->y_pos = A->y_pos;
    }

    if (B->x_pos != C->x_pos)
    {
        C->x_pos = B->x_pos;
    }

    if (C->y_pos != D->y_pos)
    {
        D->y_pos = C->y_pos;
    }

    if (D->x_pos != A->x_pos)
    {
        D->x_pos = A->x_pos;
    }
}

Rectg *createRecByParam(int x_a, int y_a, int x_b, int y_b, int x_c, int y_c, int x_d, int y_d)
{
    Rectg *rec_out = (Rectg*)malloc(sizeof(Rectg));

    Point *pA = createPoint(x_a, y_a);
    Point *pB = createPoint(x_b, y_b);
    Point *pC = createPoint(x_c, y_c);
    Point *pD = createPoint(x_d, y_d);

    isRecTrue(pA, pB, pC, pD);

    rec_out->A_point = pA;
    rec_out->B_point = pB;
    rec_out->C_point = pC;
    rec_out->D_point = pD;

    /* rec_out->A_point->x_pos = x_a;
    rec_out->A_point->y_pos = y_a;
    rec_out->B_point->x_pos = x_b;
    rec_out->B_point->y_pos = y_b;
    rec_out->C_point->x_pos = x_c;
    rec_out->C_point->y_pos = y_c;
    rec_out->D_point->x_pos = x_d;
    rec_out->D_point->y_pos = y_d; */

    return rec_out;
}

Rectg *createRecByPoints(Point *pA, Point *pB, Point *pC, Point *pD)
{
    Rectg *rec_out = (Rectg*)malloc(sizeof(Rectg));
    Point *cpA = (Point*)malloc(sizeof(Point));
    Point *cpB = (Point*)malloc(sizeof(Point));
    Point *cpC = (Point*)malloc(sizeof(Point));
    Point *cpD = (Point*)malloc(sizeof(Point));

    isRecTrue(pA, pB, pC, pD);

    cpA = pA;
    cpB = pB;
    cpC = pC;
    cpD = pD;

    rec_out->A_point = cpA;
    rec_out->B_point = cpB;
    rec_out->C_point = cpC;
    rec_out->D_point = cpD;

    return rec_out;
}

int lenSide(Point *A, Point *B)
{
    int x_vec = B->x_pos - A->x_pos;
    int y_vec = B->y_pos - A->y_pos;

    int sq_len = (x_vec * x_vec) + (y_vec * y_vec);
    double rezult = sqrt(sq_len);

    return (int)rezult;
}

SquareRectg(Rectg *currRectg)
{
    int AB = lenSide(currRectg->A_point, currRectg->B_point);
    int AD = lenSide(currRectg->A_point, currRectg->D_point);
    int S = AB*AD;

    printf("Side's length => %d and %d\n", AB, AD);
    printf("Square => %d\n", S);

    printf("Perimeter => %d\n", 2*AB + 2*AD);
}

void printRec(Rectg *currRectg)
{
    printf("Configuration:\n");
    printf("A: %d, %d\n", currRectg->A_point->x_pos, currRectg->A_point->y_pos);
    printf("B: %d, %d\n", currRectg->B_point->x_pos, currRectg->B_point->y_pos);
    printf("C: %d, %d\n", currRectg->C_point->x_pos, currRectg->C_point->y_pos);
    printf("D: %d, %d\n", currRectg->D_point->x_pos, currRectg->D_point->y_pos);

}

void deleteRectg(Rectg *currentRec)
{
    free(currentRec->D_point);
    free(currentRec->C_point);
    free(currentRec->B_point);
    free(currentRec->A_point);

    free(currentRec);
}
