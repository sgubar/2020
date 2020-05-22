#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

int main()
{
    RectgArray *theArray = createArray(4);

    Point *pointA = createPoint(3, 6);
    Point *pointB = createPoint(4, 6);
    Point *pointC = createPoint(10, 1);
    Point *pointD = createPoint(7, 6);

    Rectg *rezRec = createRecByPoints(pointA, pointB, pointC, pointD);
    Rectg *sRec = createRecByParam(5, 4, 3, 6, 1, 7, 3, 5);

    addElement(RectgArray *anArray, rezRec);
    SquareRectg(rezRec);

    sRec = createRecByParam(5, 4, 3, 6, 1, 7, 3, 5);
    addElement(theArray, sRec);
    SquareRectg(sRec);

    Point *pointA = createPoint(2, 7);
    Point *pointB = createPoint(5, 7);
    Point *pointC = createPoint(5, 0);
    Point *pointD = createPoint(2, 0);

    Rectg *rezRec = createRecByPoints(pointA, pointB, pointC, pointD);
    Rectg *sRec = createRecByParam(10, 5, 8, 2, 7, 1, 6, 3);

    addElement(RectgArray *anArray, rezRec);
    SquareRectg(rezRec);

    sRec = createRecByParam(10, 5, 8, 2, 7, 1, 6, 3);
    addElement(theArray, sRec);
    SquareRectg(sRec);

    printArray(theArray);

	FILE* theFile = fopen("rect.json", "a+");
	if (theFile != NULL)
    {
		printf("file successfully created!\n\n");
    }
	else
		return 0;

	writeArrayToJSON(theFile, theArray);
    addElementByIndex(theArray, rezRec, 0);
    addElementByIndex(theArray, sRec, 0);
    printArray(theArray);

	fflush(theFile);
	fclose(theFile);
	deleteRectg(rezRec);
    free(pointA);
    free(pointB);
    free(pointC);
    free(pointD);

    deleteRectg(sRec);
	freeArray(theArray);



	return 0;
}

