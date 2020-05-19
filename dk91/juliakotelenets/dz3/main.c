#include <stdio.h>
#include "dk_tool.h"
#include "dk_tool_array.h"

int main()
{
	EllipseArray *theArray = createArray(5);
    Point Cntr1 = {50,50};
	int R = 40;
    int r = 20;

	Ellipse *El1 = createEllipse(&Cntr1, &R, &r);
    addElement(theArray, El1);
    //printArray(theArray);
    printf("The Square of Ellipse = %f\n", SquareEllipse(El1));

	R = 50;
	r = 30;

    El1 = createEllipse(&Cntr1, &R, &r);
    addElement(theArray, El1);
    //printArray(theArray);
    printf("The Square of Ellipse = %f\n", SquareEllipse(El1));

	R = 30;
	r = 20;

    El1 = createEllipse(&Cntr1, &R, &r);
    addElement(theArray, El1);
    //printArray(theArray);
    printf("The Square of Ellipse = %f\n", SquareEllipse(El1));

	R = 60;
	r = 50;

    El1 = createEllipse(&Cntr1, &R, &r);
    addElement(theArray, El1);
    //printArray(theArray);
    printf("The Square of Ellipse = %f\n", SquareEllipse(El1));

    R = 70;
	r = 30;

    El1 = createEllipse(&Cntr1, &R, &r);
    addElement(theArray, El1);
    //addElementInIndex(theArray, El1, 1);
    printf("The Square of Ellipse = %f\n", SquareEllipse(El1));
    printArray(theArray);

	FILE* theFile = fopen("test.json", "a+");
	if (theFile != NULL)
    {
		printf("file successfully created!\n\n");
    }
	else
		return 0;

	writeArrayToJSON(theFile, theArray);
	 addElementInIndex(theArray, El1, 0);
    printArray(theArray);

	fflush(theFile);
	fclose(theFile);
	destroyEllipse(El1);
	freeArray(theArray);



	return 0;
}
