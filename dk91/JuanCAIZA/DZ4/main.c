#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "rectangle.h"

int main(int argc, const char * argv[])
{
    RectgArray *theArray = createArray(4);
    int areaOfRecArray[4];

    Point A = {3, 6};
    Point B = {4, 6};
    Point C = {4, 1};
    Point D = {3, 1};

    Rectg *rezRec = createRec(&A, &B, &C, &D);
    addElement(theArray, rezRec);

    A.y = 3;
    B.y = 3;

    rezRec = createRec(&A, &B, &C, &D);
    addElement(theArray, rezRec);

    B.x = 10;
    C.x = 10;

    rezRec = createRec(&A, &B, &C, &D);
    addElement(theArray, rezRec);

    B.x = 1;
    C.x = 1;

    rezRec = createRec(&A, &B, &C, &D);
    addElement(theArray, rezRec);

    printArray(theArray);

    for(int i = 0; i < theArray->count; i++)
    {
        areaOfRecArray[i]=round(areaOfRec(theArray->rectangles[i]));
        printf("\n Rectangle[%d]:\n%d", i, areaOfRecArray[i]);
    }

	FILE* theFile = fopen("rect.json", "a+");

	writeArrayToJSON(theFile, theArray);

    bubbleSort(theArray);
// 	selectionSort(theArray);
// 	insertionSort(theArray);
    printf("\nSorted!\n\n");

	for(int j = 0; j < theArray->count; j++)
    {
        areaOfRecArray[j]=round(areaOfRec(theArray->rectangles[j]));
        printf("\n Rectangle[%d]:\n%d", j, areaOfRecArray[j]);
    }

    freeArray(theArray);

    fflush(theFile);
	fclose(theFile);

	return 0;
}
