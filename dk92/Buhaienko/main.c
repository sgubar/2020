#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "simplesorting.h"

int main()
{

clock_t time;
char ArrayOG[10000];
char Array[10000];
int Size = 10000;
FILE *sm;
FILE *st;
st = fopen("sorted.txt", "w");
sm = fopen("sortme.txt", "r");

fscanf(sm, "%s", ArrayOG);

strcpy(Array, ArrayOG);
time = clock();
bubbule(Array, Size);
time = clock() - time;
printf("%f bubble", (double)time/CLOCKS_PER_SEC);
fputs(Array, st);
fprintf(st, "\n\n");

printf("\n\n");

strcpy(Array, ArrayOG);
time = clock();
insertion(Array, Size);
time = clock() - time;
printf("%f insertion", (double)time/CLOCKS_PER_SEC);
fputs(Array, st);
fprintf(st, "\n\n");

printf("\n\n");

strcpy(Array, ArrayOG);
time = clock();
selection(Array, Size);
time = clock() - time;
printf("%f selection", (double)time/CLOCKS_PER_SEC);
fputs(Array, st);
fprintf(st, "\n\n");

fclose(sm);
fclose(st);

return 0;
}
