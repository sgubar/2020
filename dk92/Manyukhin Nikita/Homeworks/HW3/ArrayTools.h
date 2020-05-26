#include "stdlib.h"
#include "tools.h"



typedef struct TriangleSqure
{
	int number;
	int count;

	RightTriangle **Triangles;
}RightTriangleArray;

RightTriangleArray *createArray(int aNumber);

