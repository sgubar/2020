#ifndef dk_geo_array_h
#define dk_geo_array_h

#include <stdio.h>
#include "dk_geo.h"

typedef struct tagRectangleArray
{
	int number; // number of elements (pre-requisited) in the array
	int count; // the current number of elements (inserted) to the array
	
	Rectangle **items;
}RectangleArray;

/*
{
	"number" : (int),
	"count" : (int),
	"lines" :
	[
 		 {
 			"A" : {"x" : (int), "y" : (int)},
		 	"B" : {"x" : (int), "y" : (int)},
		 	"C" : {"x" : (int), "y" : (int)},
		 	"D" : {"x" : (int), "y" : (int)}
		 },
 		{},
 		....
	]
}

*/

// init/dealloc
RectangleArray *createArray(int aNumber);
void freeArray(RectangleArray *anArray);

//interface
// returns index of added element OR -1 if fail
int addElement(RectangleArray *anArray, Rectangle *aRectangle);
void writeArrayToJSON(FILE *aFile, RectangleArray *anArray);
void printArray(RectangleArray *anArray);
void sort_simple(RectangleArray *anArray);
void sort_select(RectangleArray *anArray);
void insertionSort(RectangleArray *anArray);

void swap(int a, int b, RectangleArray *anArray);
int Compare(Rectangle *a, Rectangle *b);

#endif 
