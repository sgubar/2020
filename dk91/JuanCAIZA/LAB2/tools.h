#include <stdlib.h>
#include <stdio.h>
#include "sortResult.c"
#include <memory.h>


int *fillArray(int size);
int *copyArray(int *array, int size);
void swap(int *arr, int firtsIndex, int secondIndex);
void fprintResult(FILE *file, char label[], SortResult result, int size);
© 2020 GitHub, Inc.
