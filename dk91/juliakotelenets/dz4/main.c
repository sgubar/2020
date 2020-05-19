#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool_array.h"
#include "SimpleSort.h"
#include "dk_tool.h"

int main()
{
    EllipseArray *theArray = createArray(5);
    int SquareEllipseArray[5];
    Point Centre = {50,50};
    int R = 40;
    int r = 20;

	Ellipse *El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
     //   printf("The Square of Ellipse = %f\n", SquareEllipse(El1));


	R = 50;
	r = 30;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
      //  printf("The Square of Ellipse = %f\n", SquareEllipse(El1));


	R = 30;
	r = 20;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
      //  printf("The Square of Ellipse = %f\n", SquareEllipse(El1));


	R = 60;
	r = 50;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
       // printf("The Square of Ellipse = %f\n", SquareEllipse(El1));


    R = 70;
	r = 30;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    //printf("The Square of Ellipse = %f\n", SquareEllipse(El1));
    printArray(theArray);

	FILE* theFile = fopen("test.json", "a+");
	if (theFile != NULL)
    {
		printf("\n File successfully created!");
    }
	else
		return 0;

	writeArrayToJSON(theFile, theArray);


	int i;
	for(i=0; i<theArray->count; i++)
    {
        SquareEllipseArray[i]=round(SquareEllipse(theArray->ellipses[i]));
        printf("\n EllipseSquare[%d]=%d", i, SquareEllipseArray[i]);
    }
    bubbleSort(theArray);
    printf(" \n Sorted! \n");
int n;
   for(n = 0; n < theArray->count; n++)
    {
        SquareEllipseArray[n]=round(SquareEllipse(theArray->ellipses[n]));
        printf("\n EllipseSquare[%d]=%d", n, SquareEllipseArray[n]);
    }
    freeArray(theArray);
    fflush(theFile);
    fclose(theFile);

	return 0;
}
