#ifndef Array_h
#define Array_h
#define ERROR -2

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ArrayStruct{
	char **Array;
	char *data;
	int len;
}ArrayInfo;

//void bubbleSort(ArrayInfo *info);
//void selectionSort(ArrayInfo *info);
//void insertionSort(ArrayInfo *info);

int partitionIt(ArrayInfo *info, int aLeftIndex, int aRightIndex, char *aPivot);
void quickSort(ArrayInfo *info, int aLeftIndex, int aRightIndex);
void sort(ArrayInfo *info);

void freeArray(ArrayInfo *info);
void printArray(ArrayInfo *info);
void SaveArray(ArrayInfo *info, FILE *aFile);
ArrayInfo *LoadArray(FILE *aFile);
ArrayInfo *randomStrArray(int size, int strMaxSize);

int Search(ArrayInfo *info,char *key);
int BinarySearch(ArrayInfo *info,int left, int right, char *key);


int Compare(char *a, char *B);
void swap(ArrayInfo *info,int a, int b);

#endif 
