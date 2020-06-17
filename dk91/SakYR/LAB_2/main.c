#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
int size = 10;
char array_1[size], array_2[size];

FILE * sorting;
sorting = fopen("sorting.txt", "r+");

fscanf(sorting, "%s", array_1);

strcpy(array_2, array_1);
bubbleSort(array_2, size);
fprintf(sorting, "\n\nbubble:\n");
fputs(array_2, sorting);

strcpy(array_2, array_1);
selectionSort(array_2, size);
fprintf(sorting, "\n\nselection:\n");
fputs(array_2, sorting);

strcpy(array_2, array_1);
inclusionSort(array_2, size);
fprintf(sorting, "\n\ninclusion:\n");
fputs(array_2, sorting);

fclose(sorting);

return 0;
}
