#ifndef dk_tool_ellipse_h
#define dk_tool_ellipse_h

#include <stdio.h>
#include "dk_tool_array.h"
#include "dk_tool.h"

// EllipseArray description
typedef struct tagEllipseArray
{
	int number; // number of elements (pre-requisited) in the array
	int count; // the current number of elements (inserted) to the array

    Ellipse **ellipses;
}EllipseArray;


// Init/Dealloc
EllipseArray *createArray(int aNumber);
void freeArray(EllipseArray *anArray);
// interface
// returns index of added element OR -1 if fail
int addElement(EllipseArray *anArray, Ellipse *aEllipse);
void writeArrayToJSON(FILE *aFile, EllipseArray *anArray);
void printArray(EllipseArray* anArray);

#endif

