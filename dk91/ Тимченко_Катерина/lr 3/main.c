#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "sort.h"

int main() {
    int i = 0;
	FILE *readfile;
    readfile = fopen ("quickSort.txt", "r+");

    fseek(readfile, 0, SEEK_END);
    i = ftell(readfile);
    printf("SIZE: %f\n", i);

    fseek(readfile,0,SEEK_SET);
    int size = i;
    char a[size];

    fgets(a, size, readfile);
    printf("%s\n", a);

    fclose(readfile);

	clock_t start = clock();
	quickSort(array, 0, size(array) - 1);
	clock_t end = clock();
	printf("%s\n", array);
	printf("Quick sorting: %.5f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

	int a;
	printf("Input letter for search: ");
    scanf("%d", &a);

    int k;
    clock_t start = clock();
    k = binarySearch(a, array, size(array));
    clock_t end = clock();
    if (k != -1){
        printf("The index of the element is %d\n", k);
    }
    else{
        printf("The element isn't found!\n");
    }
        printf("Time of binary searching is %.5f sec\n\n", (double)(end - start) / CLOCKS_PER_SEC);
}
