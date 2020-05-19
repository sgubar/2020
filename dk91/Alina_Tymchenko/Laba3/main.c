#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "header.h"


void help()
{
	printf("###SYNTAX###\n\n\t./sorttest [array size] [key to find]\n\t\t[array size] must be an integer.\n\t\t[key to find] can be a char or a number.\n\n");
}

int main(int argc, char **argv)
{
	//foolproof
	if (argc <1 || atoi(argv[1]) < 0){
		help();
		return -1;
	}

	const char filepath[] = "lab3.txt";

	//opening file 4 writing chaos
	FILE *sortfile;
	if ((sortfile = fopen(filepath, "w")) == NULL){
		fileerror();
		return -1;
	}

	//placing chaotic letters (aka writing unsorted stuff)
	srand(time(NULL));
	chaosfillFile(sortfile, filepath, atoi(argv[1]));
	fclose(sortfile);

	//opening file 4 reading
	if ((sortfile = fopen(filepath, "r")) == NULL){
		fileerror();
		return -1;
	}

	//initializing stuff
	char *array;
	array = (char*)malloc(atoi(argv[1])*sizeof(char));

	//reading unsorted stuff
	for (int i = 0; i < atoi(argv[1]); i++)
		fscanf(sortfile, "%c", &array[i]);

	fclose(sortfile);

	//opening file 4 additions
	if ((sortfile = fopen(filepath, "a+")) == NULL){
		fileerror();
		return -1;
	}

	//making a timer
	clock_t start, end;

	//quick sort
	start = clock();
	quickSort(array, 0, (atoi(argv[1]) - 1));
	end = clock();
	sortResults(sortfile, filepath, "Quick", array, atoi(argv[1]), (double)(end - start));

	//linear search
	start = clock();
	int find_idx = linearSearch(array, atoi(argv[1]), *argv[2]);
	end = clock();
	searchResults(sortfile, filepath, "Linear", *argv[2], find_idx, (double)(end - start));

	//end
	free(array);
	fclose(sortfile);
	return 0;
}
