#include <stdio.h>
#include "dk_tool.h"

int main()
{
    system("chcp 1251");
    system("cls");
	Point Centre = {50,50};
	int R = 40;
    int r = 20;

	Ellipse *El1 = createEllipse(&Centre, &R, &r);

	printEllipse(El1);

	printf("Площа еліпса = %f\n", SquareEllipse(El1));

	destroyEllipse(El1);
	return 0;
}
