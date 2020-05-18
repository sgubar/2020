#include <stdio.h>
#include "dk_tool.h"

int main()
{
	Point Centre = {50,50};
	int R = 40;
    int r = 20;

	Ellipse *El1 = createEllipse(&Centre, &R, &r);

	printEllipse(El1);

	printf("The Square of Ellipse = %f\n", SquareEllipse(El1));

	destroyEllipse(El1);
	return 0;
}
