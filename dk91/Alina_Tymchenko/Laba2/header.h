#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

void bubble_sort(char *array, int size);
void insertion_sort(char *array, int size);
void selection_sort(char *array, int size);
void step(char *i, char *j) ;
void fprintResult(char *array,  int size, char fn[20]);


#endif // HEADER_H_INCLUDED
