#include <stdio.h>
#include "tools.h"
#include "ArrayTools.h"

//aaaaaaaaaaaaa4aaaaaaaa
int main()
{
    RightTriangleArray *mass = createArray(5);

    Point A = {4,8};
	Point B = {13,5};
	Point C = {13,8};

	Point X = {3,9};
	Point Y = {26,2};
	Point Z = {26,9};

	Point D = {1,4};
	Point E = {11,2};
	Point F = {11,4};

	Point G = {8,1};
	Point H = {15,5};
	Point I = {15,1};

	RightTriangle *FirstABC = createRightTriangle(&A, &B, &C);
	RightTriangle *SecondABC = createRightTriangle(&X, &Y, &Z);
	RightTriangle *ThirdABC = createRightTriangle(&D, &E, &F);
	RightTriangle *FourthABC = createRightTriangle(&G, &H, &I);

	addElement(mass, FirstABC);
	addElement(mass, SecondABC);
	addElement(mass, ThirdABC);
	addElement(mass, FourthABC);


	FILE *file = fopen("Triangle.json", "w+");
	FILE *SelectFile = fopen("Sort.txt", "w+");
	writeArrayToJSON(file, mass);
	int size = 4;
	SelectSort(mass,size);
	writeArrayToJSON(SelectFile, mass);


	fflush(file);
    fclose(file);

    fflush(SelectFile);
    fclose(SelectFile);


    freeArr(mass);

}
