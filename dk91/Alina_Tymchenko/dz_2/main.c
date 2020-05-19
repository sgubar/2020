#include <stdio.h>
#include "header.h"

int main()
{
	Point A = {6,0};
	Point B = {0,5};
	Point C = {1,0};

	printPoint(&A);
	printPoint(&B);
	printPoint(&C);

	Side *AB = createSide(&A, &B);
    Side *BC = createSide(&B, &C);
    Side *CA = createSide(&C, &A);

    Triangle *Tri =createTriangleThroughSides(AB, CA, BC);

    float a = AreaTriangle(Tri);
    printf("The Area of Triangle = %.2f\n",a);

	destroyTriangle(Tri);
	return 0;
}
