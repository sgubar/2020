#ifndef HEADER_ARRAY_H_INCLUDED
#define HEADER_ARRAY_H_INCLUDED
#include "header.h"
#include <stdio.h>

// TriangleArray description
typedef struct tagTriangleArray
{
	int number; // number of elements in the array
	int count; // the current number of elements (inserted) to the array

    Triangle **triangles;
}TriangleArray;



TriangleArray *createArray(int aNumber);
void freeArray(TriangleArray *anArray);
// interface
// returns index of added element OR -1 if fail
int addElement(TriangleArray *anArray, Triangle *aTriangle);
void writeArrayToJSON(FILE *aFile, TriangleArray *anArray);
void printArray(TriangleArray* anArray);
int addElementInIndex(TriangleArray *anArray, Triangle *aTriangle, int index);


#endif // HEADER_ARRAY_H_INCLUDED
