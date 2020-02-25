#ifndef dk_geo_h
#define dk_geo_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Rectangle description
typedef struct tagRectangle
{
	Point *A;//      A-----------B
	Point *B;//      !           !
	Point *C;//      !           !
	Point *D;//      D-----------C
}Rectangle;

// Init interface
Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D);
Rectangle *createRectangleWithPoints(Point *Ps[]);
Rectangle *createRectangleWithCoordinate(int xA, int yA, int xB, int yB, int xC, int yC, int xD, int yD);
void destroyRectangle(Rectangle *aRectangle);

float areaRectangle(Rectangle *aRectangle);
void printRectangle(Rectangle *aRectangle);

void writePointToJSON(FILE *aFile, Point *aPoint);
void writeeRectangleToJSON(FILE *aFile, Rectangle *anArray);


#endif
