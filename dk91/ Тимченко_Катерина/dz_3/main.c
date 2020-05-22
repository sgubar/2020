#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, const char * argv[])
{
    RectgArray *theArray = createArray(4);

    Point A = {3, 6};
    Point B = {4, 6};
    Point C = {4, 1};
    Point D = {3, 1};

    Rectg *rezRec = createRec(&A, &B, &C, &D);
    addElement(theArray, rezRec);

    printArray(theArray);

    A.y = 3;
    B.y = 3;

    rezRec = createRec(&A, &B, &C, &D);
    addElement(theArray, rezRec);
    areaOfRec(rezRec);

    printArray(theArray);

    B.x = 10;
    C.x = 10;

    rezRec = createRec(&A, &B, &C, &D);
    addElement(theArray, rezRec);
    areaOfRec(rezRec);

    printArray(theArray);

    B.x = 1;
    C.x = 1;

    rezRec = createRec(&A, &B, &C, &D);
    addElement(theArray, rezRec);
    areaOfRec(rezRec);

    printArray(theArray);

	FILE* theFile = fopen("rect.json", "a+");

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);

	freeArray(theArray);

	return 0;
}

