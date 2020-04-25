#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <stdio.h>


int dlina();
char schit_iz_fila(int b,char *read);
int bikvi(int b,char *read,char a[]);
int zapis(int b,char *read);

int poisk(char pisk,char *read,int b);



int partitionIt(char anArray[], int aLeftIndex, int aRightIndex, char aPivot);
 void quickSort(char anArray[], int aLeftIndex, int aRightIndex);
//void quickSort2(char anArray[], int aLeftIndex, int aRightIndex);

#endif // SORT_H_INCLUDED
