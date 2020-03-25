#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "header.h"

int main() {
     float s = 0 ;
    FILE *myfile;
    myfile = fopen ("lab2.txt", "r+");

        fseek(myfile, 0, SEEK_END);
        s = ftell(myfile);
    printf("SIZE: %f\n", s);

    fseek(myfile,0,SEEK_SET);
    int size = s;
       char a[size];

    fgets(a, size, myfile);
    printf(" %s\n", a);


fclose(myfile);
clock_t time;
char Array[50000];

    strcpy(Array, a);
    time = clock();
    bubble_sort(Array, size);
    time = clock() - time;
    printf("\n Time of Bubble Sort is  %f \n", (double)time/CLOCKS_PER_SEC);

    time = clock();
    insertion_sort(Array, size);
    time = clock() - time;
    printf(" Time of Insertion Sort is  %f \n", (double)time/CLOCKS_PER_SEC);

    time = clock();
    selection_sort(Array, size);
    time = clock() - time;
    printf(" Time of Selection Sort is  %f\n ", (double)time/CLOCKS_PER_SEC);

return 0;

}

