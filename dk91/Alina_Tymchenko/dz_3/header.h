#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <string.h>
#include <time.h>

// Point description
typedef struct tagPoint
{
	float x;
	float y;
}Point;

typedef struct tagSide
{
    float x1;
	float y1;

}Side;

// Line description
typedef struct tagTriangle
{
	Point *A;
	Point *B;
    Point *C;
    Side *AB;
    Side *AC;
    Side *BC;
    float area;
}Triangle;


// Init interface
Side *createSide(Point *A, Point *B);
Triangle *createTriangleThroughSides(Side *AB, Side *AC, Side *BC);
void destroyTriangle(Triangle *aTriangle);
float AreaTriangle(Triangle *aTriangle);
void printTriangle(Triangle *aTriangle);
void writePointToJSON(FILE *aFile, Point *aPoint);
void writeTriangleToJSON(FILE *aFile, Triangle *aTriangle);

#endif // HEADER_H_INCLUDED
