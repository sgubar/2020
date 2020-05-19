#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Line description
typedef struct tagEllipse
{
	Point *O;
	int R;
    int r;
}Ellipse;

// Init interface
Ellipse *createEllipse(Point *Centre, int *R, int *r);
void destroyEllipse(Ellipse *aEllipse);
float SquareEllipse(Ellipse *aEllipse);
void printEllipse(Ellipse *aEllipse);
void writePointToJSON(FILE *aFile, Point *aPoint);
void writeEllipseToJSON(FILE *aFile, Ellipse *aEllipses);

#endif /* dk_tool_h */
