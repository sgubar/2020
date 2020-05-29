#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

void bubble_sort(char *array, int size)
{
	for(int k=0; k<size-1; k++)
	{
    	int swaps=0;
    	for(int i=0; i<size-1-k; i++)
		{
        	if(array[i]>array[i+1])
			{
				int tmp=array[i+1];
				array[i+1]=array[i];
				array[i]=swaps;
				swaps++;
        	}
		}
    	if(!swaps)
		break;
	}
}

void insertion_sort(char *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int tmp = array[i];
        int j = i;
        while (j > 0 && array[j-1] >= tmp)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j] = tmp;
    }
}

void selection_sort(char *array, int size)
{
    for(int i = 0; i < size-1; i++)
    {
        int min = i;
        char tmp = array[i];
        for(int j = i + 1; j < size; ++j)
        {
            if (array[j] > tmp)
            {
               min = j;
               tmp = array[j];
            }
        }
        array[min] = array[i];
        array[i] = tmp;
    }
}

int GetChars(FILE* file)
{
	int size = 0;
	if (file != NULL)
	{
		fseek (file, 0, SEEK_END);
    	size = ftell (file);
    	fseek (file, 0, SEEK_SET);
    	return size-1;
	}
	else
    return -1;
}

int GetLetter(FILE* file)
{
	int size = 0;
	char value;
	int gets = GetChars(file);
	fseek(file, 0, SEEK_SET);
	if (file != NULL)
    {
    	for(int i = 0; i < gets; i++)
    	{
			fscanf (file, "%c", &value);
			if(value >= 'A' && value <= 'Z')
			{
				size++;
			}
			if(value >= 'a' && value <= 'z')
			{
				size++;
			}
		}
		return size-1;
    }
    else
    return -1;
}

char* loadFile (char* path , int *size)
{
	FILE *infile = fopen(path, "r");
	if (infile != NULL)
    {
		int gets = GetChars(infile);
    	fseek(infile, 0, SEEK_SET);

    	int letters = GetLetter(infile);
    	fseek(infile, 0, SEEK_SET);

    	int k = 0;
    	char value;
    	char *c = malloc(sizeof(char)* letters);

    	for (int i = 0; i < gets; i++)
		{
			fscanf (infile, "%c", &value);
			if(value >= 'A' && value <= 'Z')
			{
				c[k] = value;
				k++;
			}
			if(value >= 'a' && value <= 'z')
			{
				c[k] = value;
				k++;
			}
		}
    	fclose(infile);
    	*size = letters;
    	return c;
	}
	return NULL;
}

void recordToFile(char *array, int size, char *name)
{
	FILE *file;
	file = fopen(name, "w+");
	for(int i = 0; i < size; i++)
	{
	    fprintf(file,"%c\n", array[i]);
	}
	fclose(file);
}

void outputOfTheArray(char* x, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", x[i]);
	}
	printf("\n");
}


