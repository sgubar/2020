#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>

int readfile(char sorting[], char array []);
int result(char name[], int size, char *array);
void quickSort(int array[], int left, int right);
void swap(int array[], int left, int right);
int binarySearch(int a, int array[], int n);

#endif
