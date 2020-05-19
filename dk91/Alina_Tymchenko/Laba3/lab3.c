#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "header.h"

void fileerror()
{
	printf("###ERROR###\n\n\tFile could not be opened or created.\n\n");
}

char *copyArray(char *target, int size)
{
	char *copy = (char*)malloc(size*sizeof(char));
	if (NULL != copy)
	{
		for (int i = 0; i < size; i++)
			copy[i] = target[i];
	}
	return copy;
}

int chaosfillFile(FILE *file, const char filepath[], int lineSize)
{
	//wreaks havoc
	for (int i = 0; i < lineSize; i++)
	{
		int letterType = 0 + rand() % 2;

		if (letterType == 0){
			fprintf(file, "%c", ('A' + rand() % ('Z' - 'A' + 1)));
		}
		else{
			fprintf(file, "%c", ('a' + rand() % ('z' - 'a' + 1)));
		}
	}
	fprintf(file, "\n\n");
	return 0;
}

int searchResults(FILE *file, const char filepath[], const char name[], const char key, int idx, double time)
{
	fprintf(file, "Search type: %s\nKey: %c\nIndex: %d\nTime used in seconds: %f\n",
					name, key, idx, (time/CLOCKS_PER_SEC));

	return 0;
}

int sortResults(FILE *file, const char filepath[], const char name[], char *array, int size, double time)
{
	fprintf(file, "Sort type: %s\nResult: ", name);
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%c", *array);
		array++;
	}
	fprintf(file, "\n");

	fprintf(file, "Array size: %d\nTime used in seconds: %f\n\n",
						size, (time/CLOCKS_PER_SEC));

	return 0;
}

//linear search
int linearSearch(char *array, int size, const char key)
{
	for (int i = 0; i < size; i++)
	{
		if (key == array[i])
		{
			return i;
		}
	}
	return -1;
}

//quick sort
	//sort
void quickSort(char *array, int start, int end)
{
	if (start < end)
	{
		int pivot = partition(array, start, end);

		quickSort(array, start, pivot - 1);
		quickSort(array, pivot + 1, end);
	}
}

	//help function
	//метод возвращающий индекс опорного элемента
int partition(char *array, int start, int end)
{
    char pivot = array[end];

    char *temp_c;
	temp_c = (char*)malloc(sizeof(char));

    int i = (start - 1);

    for (int j = start; j <= (end - 1); j++)
    {
        if (array[j] <= pivot)
        {
            i++;

            *temp_c = array[i];
			array[i] = array[j];
			array[j] = *temp_c;
        }
    }

    *temp_c = array[i + 1];
	array[i + 1] = array[end];
	array[end] = *temp_c;

    return (i + 1);
}
