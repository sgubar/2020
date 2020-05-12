#include "dk_ellipse3.h"
#include "dk_arrellipse3.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    EllipseArr *mass = createArr(5);
    Point A = {-12, 0};
    Point B = {0, 7};
    Point C = {12, 0};
    Point D = {0, -7};
    Point Centre = {3,3};

    Point X = {-10, 0};
    Point Y = {0, 5};
    Point Z = {10, 0};
    Point K = {0, -5};
    Point ACentre = {1,1};

    Ellipse *one = createEllipse(&A, &B, &C, &D,&Centre);
    Ellipse *two = createEllipse(&X, &Y, &Z, &K,&ACentre);
    Eladder(mass, one);
    Eladder(mass, two);

    FILE *Filex = fopen("Elliopse.txt", "a+");

    Arr_writer(Filex, mass);

    fflush(Filex);
    fclose(Filex);

    freeArr(mass);
}

