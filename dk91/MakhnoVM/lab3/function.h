#include <stdio.h>
#include <stdlib.h>
typedef struct arrAndlength
{
	int length;
	char** array_s;

}arrayinfo;
int size_file();
arrayinfo* fillingArr(char* n, int size_f);				//фукція отримання інформації з файлу
void quickSort(char **s_arr, int first, int last);
void filePrintf(arrayinfo* cp);
void binarySearch(char* key, char** k, int left, int right);
