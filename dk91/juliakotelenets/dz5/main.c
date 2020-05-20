#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool_array.h"
#include "Sort.h"
#include "dk_tool.h"

int main()
{
    EllipseArray *theArray = createArray(5);
    Point Centre = {50,50};
    int R = 40;
    int r = 20;

	Ellipse *El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("The Square of Ellipse 1 = %f\n", SquareEllipse(El1));


	R = 50;
	r = 30;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("The Square of Ellipse 2 = %f\n", SquareEllipse(El1));


	R = 30;
	r = 20;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("The Square of Ellipse 3 = %f\n", SquareEllipse(El1));


	R = 60;
	r = 50;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("The Square of Ellipse 4 = %f\n", SquareEllipse(El1));


    R = 70;
	r = 30;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("The Square of Ellipse 5 = %f\n", SquareEllipse(El1));
    printArray(theArray);
    sort_shell(theArray);
    printf(" \n Sorted! \n");
    printArray(theArray);

    lineSearch(theArray, 4712);


	FILE* theFile = fopen("test.json", "a+");
	if (theFile != NULL)
    {
		printf("\n File successfully created! \n");
    }
	else
		return 0;

	writeArrayToJSON(theFile, theArray);
    freeArray(theArray);
    fflush(theFile);
    fclose(theFile);

	return 0;
}
