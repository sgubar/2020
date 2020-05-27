#include "stdlib.h"
#include "tools.h"



typedef struct TriangleSqure
{
	int number;
	int count;

	RightTriangle **Triangles;
}RightTriangleArray;

RightTriangleArray *createArray(int aNumber);
void freeArr(RightTriangleArray *anArray);
void DestroyArray(RightTriangleArray *anArray);
int addElement(RightTriangleArray *anArray, RightTriangle *aTriangle);
void writeArrayToJSON(FILE *file, RightTriangleArray *anArray);
void quickSort(RightTriangleArray *anArray, int aLeftIndex, int aRightIndex);
int line_search(RightTriangleArray *anArray, float search);