#include <stdio.h>
#include <stdlib.h>
typedef struct arrAndlength
{
	int length;
	char** array_s;

}arrayinfo;
arrayinfo* fillingArr();				//фукція отримання інформації з файлу
void bobbleSort();
void insertionSort();
void selectionSort();
