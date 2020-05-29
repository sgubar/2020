#ifndef DK_TOOL_H_INCLUDED
#define DK_TOOL_H_INCLUDED
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


#endif // DK_TOOL_H_INCLUDED
