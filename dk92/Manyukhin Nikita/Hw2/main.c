#include <stdio.h>
#include "tools.h"

int main()
{


    Point A = {4,10};
	Point B = {3,5};
	Point C = {3,10};

    RightTriangle *ABC = createRightTriangle(&A, &B, &C);

    if (ABC == NULL)
    {
        printf("####ERROR####\n");
    }else
    {
        printf("Square = %.2f\n", (float)AreaOfRightTriangle(ABC));
    }

    destroyRightTriangle(ABC);
}
