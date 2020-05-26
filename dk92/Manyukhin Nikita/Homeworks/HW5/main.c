#include <stdio.h>
#include "tools.h"
#include "ArrayTools.h"

//aaaaaaaaaaaaa4aaaaaaaa4
int main()
{
    float search;
    int choice;
    RightTriangleArray *mass = createArray(5);

    //1
    Point A = {4,8};
	Point B = {7,5};
	Point C = {7,8};

	//2
	Point X = {3,9};
	Point Y = {1,2};
	Point Z = {1,9};

	//3
	Point D = {1,4};
	Point E = {11,2};
	Point F = {11,4};

	//4
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
	writeArrayToJSON(file, mass);

	FILE *QuickFile = fopen("QuickSort.txt", "w+");
    quickSort(mass, 0, mass->count - 1);
    writeArrayToJSON(QuickFile, mass);

    printf("Enter the area of Triangle: ");
	scanf("\n%f", &search);
	choice = line_search(mass, search);
	printf("\nPosition of a triangle = %d\n\n", choice);


	fflush(file);
    fclose(file);

    fflush(QuickFile);
    fclose(QuickFile);


    freeArr(mass);

}
