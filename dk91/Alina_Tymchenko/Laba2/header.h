#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

void bubble_sort(char *array, int n);
void output_of_the_array(char* x, int size);
void sort_insert(char *array, int size);
void sort_selection(char *array, int size);
void record_to_file(char *array, int size, char *name);
int GetLetterAmountInFile (FILE* file);
int GetCharsAmountInFile (FILE* file);
char* loadFile (char *path , int *size);


#endif // HEADER_H_INCLUDED
