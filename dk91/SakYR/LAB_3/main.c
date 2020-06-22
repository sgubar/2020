#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main()
{
int size = 20000;
char simvol;
char array_1[size];

FILE *sorting;
sorting = fopen("sorting.txt", "r+");

fscanf(sorting, "%s", array_1);


printf("Look for: \n");
scanf("%c", &simvol);
fprintf(sorting, "Index : [%i]\n", linearSearch(array_1, simvol));

clock_t start = clock();
ShallSort(array_1, size);
clock_t end = clock();
printf ("Shall = %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);
fprintf(sorting, "\n\nShall:\n");
fputs(array_1, sorting);


fclose(sorting);

return 0;
}
