#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>

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
Triangle *createTriangle(Point *A, Point *B, Point *C);
Side *createSide(Point *A, Point *B);
Triangle *createTriangleThroughSides(Side *AB, Side *AC, Side *BC);
void printPoint(Point *aPoint);
void destroyTriangle(Triangle *aTriangle);
float AreaTriangle(Triangle *aTriangle);
void printTriangle(Triangle *aTriangle);


#endif // HEADER_H_INCLUDED
