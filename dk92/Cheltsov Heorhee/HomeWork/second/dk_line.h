//
// Created by chelt on 22.04.2020.
//

#ifndef HOMEWORK2_DK_LINE_H
#define HOMEWORK2_DK_LINE_H


// Point description
typedef struct tagPoint
{
    int x;
    int y;
}Point;


typedef struct tagfigura
{
    Point *A;
    Point *B;
    Point *C;
    Point *D;
}Figura;

Figura *createFiguruAndPoints(Point *A, Point *C);
int sqea(Figura *aFigura);
void printFigura(Figura *aFigura);
void destroyFigura(Figura *aFigura);

/* Init interface
float lenghLine(Line *aLine);
void printLine(Line *aLine); */

#endif //HOMEWORK2_DK_LINE_H
