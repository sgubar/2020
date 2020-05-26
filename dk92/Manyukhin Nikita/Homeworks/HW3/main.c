#include <stdio.h>
#include "tools.h"
#include "ArrayTools.h"

//aaaaaaaaaaaaa
int main()
{
    RightTriangleArray *mass = createArray(5);

    Point A = {4,8};
	Point B = {13,5};
	Point C = {13,8};

	Point X = {3,9};
	Point Y = {26,2};
	Point Z = {26,9};

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
