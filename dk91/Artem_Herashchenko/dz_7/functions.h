#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Square description
typedef struct tagLine
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Square;

typedef struct tagSquareArray
{
	int number;
	int count;

	float *ploschaSquare;

	Square **Squares;
}SquareArray;

// Init interface
Square *createSquare(Point *A, Point *B, Point *C, Point *D);
void EnteringCoordinates (int *X, int *Y);
void destroySquare(Square *aSquare);
void writeSquareToJSON(FILE *aFile, Square *aSquare);
void writePointToJSON(FILE *aFile, Point *aPoint);
SquareArray *createArray(int aNumber);
void freeArray(SquareArray *anArray);
int addElement(SquareArray *anArray, Square *aSquare, float ploscha);
void writeArrayToJSON(FILE *aFile, SquareArray *anArray);
float ploschaSquare(Square *aSquare);
void sort_vstavka(SquareArray *anArray);
void quickSort( SquareArray *anArray, int l, int r);
int partition(SquareArray *anArray, int l, int r);
int linijnyj_poshuk(SquareArray *anArray, float key);

#endif // FUNCTIONS_H_INCLUDED

