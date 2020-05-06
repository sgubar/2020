#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"

void bobbleSort()
{
	arrayinfo* cp;
	cp = fillingArr();
	char* c;

	clock_t start = clock();

	for(int i = cp->length; i > 0; i--)
	{
		for(int j = 0; j < i - 1; j++)
		{
			if(strcmp(cp->array_s[j], cp->array_s[j + 1]) > 0)
			{
				c = cp->array_s[j];
				cp->array_s[j] = cp->array_s[j + 1];
				cp->array_s[j + 1] = c;
			}
		}
	}
	int j = 0;

	clock_t end = clock();
    printf ("bobble = %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);

	FILE *fo;
	fo = fopen("bubbleSort.txt", "w");
	for(int i = 0; i < cp->length; i++)
	{
		while( cp->array_s[i][j] != '\n')
		{
		 	fprintf(fo, "%c", cp->array_s[i][j]);
		 	j++;
		}
		fprintf(fo, " ");
		j = 0;
	}

	
	fclose(fo);
}





void selectionSort()
{
	arrayinfo* cp = fillingArr();
	char* c;
	int j = 0;

	clock_t start = clock();

	for(int i = 0; i < cp->length; i++)
	{
		int min = i;
		for(int j = i + 1; j < cp->length; j++)
		{
			if(strcmp(cp->array_s[min], cp->array_s[j]) > 0)
			{
				min = j;
			}
		}
		c = cp->array_s[i];
		cp->array_s[i] = cp->array_s[min];
		cp->array_s[min] = c;
	}

	clock_t end = clock();
    printf ("selection = %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);

	FILE *fp;
	fp = fopen("selectionSort.txt", "w");
	for(int i = 0; i < cp->length; i++)
	{
		while(cp->array_s[i][j] != '\t')
		{
		 	fprintf(fp, "%c", cp->array_s[i][j]);
		 	j++;
		}
		fprintf(fp, " ");
		j = 0;
	}


	
	fclose(fp);
	free(cp);                   
}



void insertionSort()
{
	arrayinfo* cp = fillingArr();
	char* c;
	int j = 0;

	clock_t start = clock();

	for(int i = 0; i < cp->length; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(strcmp(cp->array_s[j - 1], cp->array_s[j]) > 0)
			{
				c = cp->array_s[j - 1];
				cp->array_s[j - 1] = cp->array_s[j];
				cp->array_s[j] = c;
			}else break;
		}
	}

	clock_t end = clock();
    printf ("insertion = %.10lf\n", (double)(end - start)/CLOCKS_PER_SEC);

	FILE *fo;
	fo = fopen("insertionSort.txt", "w");
	for(int i = 0; i < cp->length; i++)
	{
		while(cp->array_s[i][j] != '\n')
		{
		 	fprintf(fo, "%c", cp->array_s[i][j]);
		 	j++;
		}
		fprintf(fo, " ");
		j = 0;
	}

	
	fclose(fo);
}