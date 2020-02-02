//
//  dk_line.h
//  dz2
//
//  Created by Slava Gubar on 2/15/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#ifndef dk_line_h
#define dk_line_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Line description
typedef struct tagLine
{
	Point *A;
	Point *B;
}Line;

// Init interface
Line *createLine(Point *A, Point *B);
Line *createLineWithCoordinate(int xA, int yA, int xB, int yB);
void destroyLine(Line *aLine);

float lenghLine(Line *aLine);
void printLine(Line *aLine);

#endif /* dk_line_h */
