#ifndef LABA4_H_INCLUDED
#define LABA4_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct el{
    int* pred;
    int element;
    int* next;
}el;
int loneinost(struct el *n, int kol);
void rendomm(struct el *n, int kol);
int deleteE(struct el *n,int kol,int udal);
void vivod(struct el *n,int kol);
#endif // LABA4_H_INCLUDED
