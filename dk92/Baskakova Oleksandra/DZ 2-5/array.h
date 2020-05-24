#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include "triangles.h"

typedef struct array {
    int size;
    int count;
    Triangle* triangles;

} Array;

Array *createArray(int size);
Triangle getByIndex( Array *array, int index);
int pushToArray(Array **array, Triangle triangle);
int setByIndex(Array **array, Triangle triangle, int index);
void printArray(Array *array);
void deleteArray(Array *array);
void serializeArrayToJson(FILE *file, Array *array);
void bubbleSort(Array *arr);
void selectionSort(Array *arr);
void insertionSort(Array *arr);
void shellSort(Array *arr);
Triangle *linearSearch(Array *arr, float area);
#endif
