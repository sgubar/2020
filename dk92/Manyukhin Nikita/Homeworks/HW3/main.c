#include <stdio.h>
#include "tools.h"
#include "ArrayTools.h"


int main()
{
    RightTriangleArray *mass = createArray(5);

    Point A = {4,9};
	Point B = {3,5};
	Point C = {3,9};

	Point X = {3,1};
	Point Y = {7,2};
	Point Z = {7,1};

	RightTriangle *FirstABC = createRightTriangle(&A, &B, &C);
	RightTriangle *SecondABC = createRightTriangle(&X, &Y, &Z);
	addElement(mass, FirstABC);
	addElement(mass, SecondABC);

	FILE *file = fopen("Triangle.json", "w+");
	writeArrayToJSON(file, mass);

	fflush(file);
    fclose(file);

    freeArr(mass);

}
