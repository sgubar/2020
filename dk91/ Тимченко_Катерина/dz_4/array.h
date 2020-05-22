#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <stdio.h>
#include "rectangle.h"

typedef struct tagRectgArray
{
	int number; // number of elements (pre-requisited) in the array
	int count; // the current number of elements (inserted) to the array

    Rectg **rectangles;
}RectgArray;


RectgArray *createArray(int aNumber);
void freeArray(RectgArray *anArray);

// returns index of added element OR -1 if fail
int addElement(RectgArray *anArray, Rectg *currRectg);
void writeArrayToJSON(FILE *aFile, RectgArray *anArray);
void printArray(RectgArray* anArray);

void bubbleSort(RectgArray *anArray);
void selectionSort(RectgArray *anArray);
void insertionSort(RectgArray *anArray);

#endif // ARRAY_H_INCLUDED
