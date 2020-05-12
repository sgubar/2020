
#ifndef DK_ARRELLIPSE3_H
#define DK_ARRELLIPSE3_H


typedef struct tagArrayofEllipses
{
    int number;
    int Count;

    Ellipse **Ellipses;
}EllipseArr;

EllipseArr *createArr(int Val);
void Arr_writer(FILE *eFile, EllipseArr *aArr);
void Point_writer(FILE *eFile, Point *ePoint);
int Eladder(EllipseArr *aArr, Ellipse *eEllipse);
void freeArr(EllipseArr *aArr);


#endif
