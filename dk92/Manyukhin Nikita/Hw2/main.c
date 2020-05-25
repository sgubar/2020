#include <stdio.h>
#include "tools.h"

int main()
{


    Point A = {4,9};
	Point B = {-2,5};
	Point C = {-2,9};

    RightTriangle *ABC = createRightTriangle(&A, &B, &C);

    if (ABC == NULL)
    {
        printf("####ERROR####\n");
    }else
    {
        PrintRightTriangle(ABC);
        printf("S(ABC) = %.2f\n", (float)AreaOfRightTriangle(ABC));
    }

    destroyRightTriangle(ABC);
}
