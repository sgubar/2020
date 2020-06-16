#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fun.h"

int main() {
   FILE *txt_file = fopen("Text.txt" , "rt");
    Open();
    fseek (txt_file, 0, SEEK_END);
    long length = ftell(txt_file);
    fclose(txt_file);
    printf("Length of file: %i elements\n" , length);
    FILE *txt_file1 = fopen("Text.txt" , "rt");
    char *aArray = (char *) malloc(sizeof(char) * length);
    fgets(aArray, length, txt_file1);
   // fclose(txt_file1);
   printf("Shellsort started\n");
    clock_t first = clock();
     ShellSort( aArray,  length);
     clock_t second = clock();
    float time = second - first;
        printf("Time sorting: %0.10f\n", time/CLOCKS_PER_SEC);
     searchArray(aArray, length);
    inPut( length,  aArray);
}
