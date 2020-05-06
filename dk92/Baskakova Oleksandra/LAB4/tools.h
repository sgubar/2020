#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

unsigned int getUnsignedInt(char* label);
void *createArray(int size);
void fprintResult(FILE *file, char label[], int *result, int size);
int linearSearch(int *array, int size, int element);