#include <math.h>
#include <stdlib.h>
#include "rectangle.h"
#include "array.h"

Point *copyPointWithPoint(Point *aPonit);
Point *creatPointByParam(int x, int y);

Rectg *createRec(Point *A, Point *B, Point *C, Point *D)
{

    if (NULL != A && NULL != B && NULL != C && NULL != D)
    {
      Rectg *rec_out = (Rectg*)malloc(sizeof(Rectg));

      if (NULL != rec_out)
      {
          rec_out->A = copyPointWithPoint(A);
          rec_out->B = copyPointWithPoint(B);
          rec_out->C = copyPointWithPoint(C);
          rec_out->D = copyPointWithPoint(D);
      }

      return rec_out;
    }
}

Rectg *createRecByParam(int x_a, int y_a, int x_b, int y_b, int x_c, int y_c, int x_d, int y_d)
{
    Rectg *rec_out = (Rectg*)malloc(sizeof(Rectg));

    Point *pA = creatPointByParam(x_a, y_a);
    Point *pB = creatPointByParam(x_b, y_b);
    Point *pC = creatPointByParam(x_c, y_c);
    Point *pD = creatPointByParam(x_d, y_d);

    isRecTrue(pA, pB, pC, pD);

    rec_out->A = pA;
    rec_out->B = pB;
    rec_out->C = pC;
    rec_out->D = pD;

    return rec_out;
}

void isRecTrue(Point *A, Point *B, Point *C, Point *D)
{
    if (A->y != B->y)
    {
        B->y = A->y;
    }

    if (B->x != C->x)
    {
        C->x = B->x;
    }

    if (C->y != D->y)
    {
        D->y = C->y;
    }

    if (D->x != A->x)
    {
        D->x = A->x;
    }
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

    rec_out->A = cpA;
    rec_out->B = cpB;
    rec_out->C = cpC;
    rec_out->D = cpD;

    return rec_out;
}

void deleteRectg(Rectg *currRectg)
{
    free(currRectg->D);
    free(currRectg->C);
    free(currRectg->B);
    free(currRectg->A);

    free(currRectg);
}

int lenSide(Point *A, Point *B)
{
    int x_AB = B->x - A->x;
    int y_AB = B->y - A->y;

    int sq_len_x = (x_AB * x_AB);
    int sq_len_y = (y_AB * y_AB);
    int sq_len = sq_len_x + sq_len_y;
    double AB = sqrt(sq_len);

    return (int)AB;
}

float areaOfRec(Rectg *currRectg)
{
    float S = 0.0;

	if (NULL != currRectg)
	{
		int AB = lenSide(currRectg->A, currRectg->B);
        int AD = lenSide(currRectg->A, currRectg->D);
        S = AB*AD;
	}

	return (float)S;
}

void printRec(Rectg *currRectg)
{
    if(NULL != currRectg)
    {
        printf("Configuration:\n");
        printf("A: %d, %d\n", currRectg->A->x, currRectg->A->y);
        printf("B: %d, %d\n", currRectg->B->x, currRectg->B->y);
        printf("C: %d, %d\n", currRectg->C->x, currRectg->C->y);
        printf("D: %d, %d\n", currRectg->D->x, currRectg->D->y);

    }

}

Point *copyPointWithPoint(Point *aPonit)
{
    Point *rec_out = (Point *)malloc(sizeof(Point));
	if (NULL != rec_out)
	{
	    // Ïðèñâàèâàíèå óêàçàòåëþ rec_out->x çíà÷åíèÿ óêàçàòåëÿ aPoint -> õ
        // (ñîçäàííûé íîâûé óçåë)
		rec_out->x = aPonit->x;
		rec_out->y = aPonit->y;
	}

	return rec_out;
}

Point *creatPointWithCoordinate(int x, int y)
{
	Point *rec_out = (Point *)malloc(sizeof(Point));
	if (NULL != rec_out)
	{
		rec_out->x = x;
		rec_out->y = y;
	}

	return rec_out;
}


void writePointToJSON(FILE *aFile, Point *aPonit)
{
	if (NULL == aPonit || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPonit->x, aPonit->y);
}

void writeRecToJSON(FILE *aFile, Rectg *currRectg)
{
	if (NULL == currRectg || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, currRectg->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, currRectg->B);
	fprintf(aFile, ", \n\"C\" : ");
	writePointToJSON(aFile, currRectg->C);
	fprintf(aFile, ", \n\"D\" : ");
	writePointToJSON(aFile, currRectg->D);
	fprintf(aFile, "\n}");
}

Point *creatPointByParam(int x, int y)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = x;
		theResult->y = y;
	}

	return theResult;
}
