#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#include <stdio.h>
#include <time.h>

void bubbleSort(char a[], int n);
void insertionSort(char arr[], int n);
void selectionSort(char arr[], int n);

//void fprintResult(FILE *file, char label[],  int size);
void swap(char *xp, char *yp) ;

void fprintResult(char array[],  int size);

#endif
