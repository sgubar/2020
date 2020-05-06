#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>

int readfile(char sorting[], char array[]) {
	FILE *file = fopen("quickSort.txt", "r+");
	if(file == NULL) {
    	printf("Not found\n");
    }

	int count = 0;
	while (fgets(file) != NULL) {
		char tmp = fgets(file);
	    if(((int)tmp >= 65 && (int)temp <= 90) || ((int)tmp>=97 && (int)tmp <= 122)) {
	    	array[count] = tmp;
	        count++;
	    }
	}
	fclose(file);
	return count;
}

int result(char name[], int size, char *array) {
	FILE *file = fopen(name, "r+");
	fprintf(file,"Result:\n");
	if(file == NULL) {
    	printf("Error! File is not found\n");
    }

	for(int i = 0; i < size; i++)
	{
	    fprintf(file,"%c\n", array[i]);
	}
	fclose(file);

}

void quickSort(char *array, int left, int right){
    int i, j, pivot, tmp;
	
	if (right > left){
        int pivot = left;
        int i = left;
	    int j = right;

	    while(i < j){
            while(array[i] <= array[pivot] && i < right){
                i++;
            }
		    while(array[j] > array[pivot]){
                j--;
		    }
		    if(i <= j) {
			    tmp = array[i];
			    array[i] = array[j];
			    array[j] = tmp;
		    }
	    }
	    tmp = array[pivot];
	    array[pivot]=array[i];
	    array[j]=tmp;
	    quickSort(array, left, j - 1);
	    quickSort(array, j + 1, right);
   }
}

int binarySearch(int a, int array[], int n) {
    int mediana;
	int left = 0;
    int right = n - 1;

	while (left <= right) {
        mediana = (left + right)/2;
        if (a < array[mediana]){
            right = mediana - 1;
        }
        else if (a > array[mediana]){
            left = mediana + 1;
        }
        else{
            return mediana;
        }
    }
    if (a == -1){
        printf("Not found!\n");
    }
    return -1;
}
