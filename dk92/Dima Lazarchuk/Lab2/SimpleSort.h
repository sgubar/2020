#ifndef SimpleSort_h
#define SimpleSort_h
#define ERROR -2

#include <stdio.h>
#include <ctype.h>

typedef struct Word
{
	struct Word *pr;
	char *str;
	struct Word *next;
}Word;

void bubbleSort(Word *Start, Word *End);
void selectionSort(Word *Start, Word *End);
void insertionSort(Word *Start, Word *End);


int Compare(char *a, char *B);

void swap(Word *a, Word *b);

void swappoints(Word *a, Word *b);

#endif 
