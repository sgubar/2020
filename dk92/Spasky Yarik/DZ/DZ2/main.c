#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"


int main()
{
	  Point A = {-5, 0};
    Point B = {0, 2};
    Point C = {5, 0};
    Point D = {0, -2};
    Point Centre = {0,0};


	Ellipse *Ellips = createEllipse(&A, &B, &C, &D, &Centre);

    if(Ellips == NULL)
        printf("ERROR\n");
    else
            printf("The Square of Ellipse = %d\n", Ellipse_Area(Ellips));


	destroyEllipse(Ellips);
}
