//
//  dk_line_array.h
//  dz3
//
//  Created by Slava Gubar on 3/1/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#ifndef dk_line_array_h
#define dk_line_array_h

#include <stdio.h>
#include "dk_line.h"

typedef struct tagLineArray
{
	int number; // number of elements (pre-requisited) in the array
	int count; // the current number of elements (inserted) to the array
	
	Line **lines;
}LineArray;

/*
{
	"number" : (int),
	"count" : (int),
	"lines" :
	[
 		 {
 			"A" : {"x" : (int), "y" : (int)},
		 	"B" : {"x" : (int), "y" : (int)}
		 },
 		{},
 		....
	]
}

*/

// init/dealloc
LineArray *createArray(int aNumber);
void freeArray(LineArray *anArray);

//interface
// returns index of added element OR -1 if fail
int addElement(LineArray *anArray, Line *aLine);
void writeArrayToJSON(FILE *aFile, LineArray *anArray);
void printArray(LineArray *anArray);
void sort_simple(LineArray *anArray);
void sort_select(LineArray *anArray);

#endif /* dk_line_array_h */
