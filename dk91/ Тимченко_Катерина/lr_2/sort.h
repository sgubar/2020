#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>


void bubble_sort(char *array, int size);
void insertion_sort(char *array, int size);
void selection_sort(char *array, int size);
int GetChars(FILE* file);
int GetLetter(FILE* file);
char* loadFile (char* path , int *size);
void recordToFile(char *array, int size, char *name);
void outputOfTheArray(char* x, int size);

#endif // SORT_H_INCLUDED
