#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "InputSort.h"
#include "SortLib.h"

int main()
{
	int size;
	printf("Enter the size of the line:\n");
	scanf("%u", &size);
	FILE *fp;
	genFile("name.txt", size);
	struct timespec algtime;
	while(1){
		printf("\n");
		
		char *mass = malloc(size * sizeof(char));
		fp = fopen("name.txt", "r");
		for(;fp == NULL;)
		{
			fp = fopen("name.txt", "r");
			printf("F\n");
		}
		fscanf(fp, "%[^\n]", mass);			
		int n;
		printf("Sort Bubble(1), Choose(2), Paste(3), regen line(4), exit program(99)\n");
		scanf("%i", &n);
		for (int b = 0; b < size; ++b)
		{
			printf("%c", (*(mass + b)));
		}
		printf("\n");

		switch(n)
		{
			case 1: printf("Program execution time %lu nanoseconds.\n", bubblesort(mass));printf("Print f to \n");free(mass);
			break;
			case 2: printf("Program execution time %lu nanoseconds.\n", choosesort(mass));printf("Print f to \n");free(mass);
			break;
			case 3: printf("Program execution time %lu nanoseconds.\n", pastesort(mass));printf("Print f to \n");free(mass);
			break;
			default: printf("try again! \n");printf("Print f to \n");free(mass);
			break;
			case 4: printf("Enter the size of the line:\n");
					scanf("%u", &size);
					genFile("name.txt", size);
					printf("Print f to \n");
					free(mass);
			break;
			case 99:fclose(fp);
			free(mass);
			return 0;
		}
		
		
	}
	fclose(fp);

	return 0;
}