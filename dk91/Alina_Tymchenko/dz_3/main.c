#include <stdio.h>
#include "header.h"
#include "header_array.h"

int main()
{
	TriangleArray *theArray = createArray(8);
    Point A = {6,0};
	Point B = {0,5};
	Point C = {1,0};

    Side *AB = createSide(&A, &B);
    Side *BC = createSide(&B, &C);
    Side *CA = createSide(&C, &A);

    Triangle *Tri =createTriangleThroughSides(AB, CA, BC);
    addElement(theArray, Tri);
    //printArray(theArray);
    float area = AreaTriangle(Tri);
    printf("The Area of Triangle = %.2f\n",area);

	A.x = 4;
	A.y = 0;
	B.x = 1;
	B.y = 0;
	C.x = 3;
	C.y = 6;

    AB = createSide(&A, &B);
    BC = createSide(&B, &C);
    CA = createSide(&C, &A);

    Tri =createTriangleThroughSides(AB, CA, BC);
    addElement(theArray, Tri);
    //printArray(theArray);
    area = AreaTriangle(Tri);
    printf("The Area of Triangle = %.2f\n",area);
	A.x = 8;
	A.y = 5;
	B.x = 8;
	B.y = 3;
	C.x = 7;
	C.y = 4;

    AB = createSide(&A, &B);
    BC = createSide(&B, &C);
    CA = createSide(&C, &A);

    Tri =createTriangleThroughSides(AB, CA, BC);
    addElement(theArray, Tri);
    //printArray(theArray);
    area = AreaTriangle(Tri);
    printf("The Area of Triangle = %.2f\n",area);

	A.x = 0;
	A.y = 4;
	B.x = 4;
	B.y = 4;
	C.x = 4;
	C.y = 1;

    AB = createSide(&A, &B);
    BC = createSide(&B, &C);
    CA = createSide(&C, &A);

    Tri =createTriangleThroughSides(AB, CA, BC);
    addElement(theArray, Tri);
    //printArray(theArray);
    area = AreaTriangle(Tri);
    printf("The Area of Triangle = %.2f\n",area);

    A.x = 5;
	A.y = 2;
	B.x = 9;
	B.y = 3;
	C.x = 6;
	C.y = 7;

    AB = createSide(&A, &B);
    BC = createSide(&B, &C);
    CA = createSide(&C, &A);

    Tri =createTriangleThroughSides(AB, CA, BC);
    addElement(theArray, Tri);
    //printArray(theArray);
    area = AreaTriangle(Tri);
    printf("The Area of Triangle = %.2f\n",area);
    printArray(theArray);

	FILE* theFile = fopen("triangles.json", "a+");
	if (theFile != NULL)
    {
		printf("file successfully created!\n\n");
    }
	else
		return 0;

	Tri =createTriangleThroughSides(AB, BC, CA);

	writeArrayToJSON(theFile, theArray);
    addElementInIndex(theArray, Tri, 0);
    printArray(theArray);

	fflush(theFile);
	fclose(theFile);
//	destroyTriangle(Tri);
	freeArray(theArray);



	return 0;
}
