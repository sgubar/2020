#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
char **arr = NULL;
arrayinfo *cp;
int size_file();

arrayinfo* fillingArr()
{
	
	int size_f = size_file() - 1;
	char *n = (char*)malloc(size_f * sizeof(char));
	arr = (char**)malloc(size_f * sizeof(char*));
	int j = 0;
	

	
	FILE *fi;
	fi = fopen("data.txt", "rt");
	int i = 0;
	while(!feof(fi))
	{
		fscanf(fi, "%c", &n[i]);	
		i++;
	}
	fclose(fi); 

	
	
	i = 0;
	if((n[0] >= 'a' && n[0] <= 'z') || (n[0] >= 'A' && n[0] <= 'Z'))
	{
		arr[0] = &n[0];
		i = 1;
		j = 1;
	}
	for(; i < size_f; i++)
	{
		if(((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z')) && (n[i-1] == ' ' || n[i-1] == '\n' || n[i-1] == '\t'))
		{
			arr[j] = &n[i];
			j++;
		}
	}
	cp = (arrayinfo *)malloc(sizeof(arrayinfo));
	cp->length = j;
	cp->array_s = (char**)malloc(j * sizeof(char*));
	for(i = 0; i < cp->length; i++)cp->array_s[i] = arr[i];
	return cp;
}
	

int size_file()
{

	FILE *fo;
	char name;
	fo = fopen("data.txt", "rt");
	int i = 0;

	while(!feof(fo)){
		fscanf(fo, "%c", &name);
		i++;
	}
	fclose(fo);
	return i;
}


