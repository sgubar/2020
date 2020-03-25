
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "SORTIROVCA.h"
int alg ( const void *a, const void *b) {

    return (*(char*)b - *(char*)a );
}

void sort( char* eter, int longo ) {
   qsort(eter, longo, sizeof(char), alg);
   printf("%s\n", eter);
}
