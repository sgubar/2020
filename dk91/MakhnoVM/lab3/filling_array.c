#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"




arrayinfo* fillingArr(char* n, int size_f)
{
	char **arr = NULL;
	arrayinfo *cp;
	arr = (char**)malloc(size_f * sizeof(char*));				//виділення пам'яті під масив
	int j = 0;
	

	
	FILE *fi;
	fi = fopen("data1.txt", "rt");
	int i = 0;								//зчитування з файлу
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
		if(((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z')) && (n[i-1] == ' ' || n[i-1] == '\n' || n[i-1] == '\t'))	//знаходження вказівників на початки слів
		{
			arr[j] = &n[i];
			j++;
			n[i-1] = '\0';
		}
	}

	

	cp = (arrayinfo *)malloc(sizeof(arrayinfo));		//виділення пам'яті під структуру

	cp->length = j;						//присвоєння значення довжини масиву вказівників слів

	cp->array_s = (char**)malloc(j * sizeof(char*));			//виділення пам'яті під массив для стуктури

	for(i = 0; i < cp->length; i++)cp->array_s[i] = arr[i];		//передача вказівників до структури


	free(arr);					//звільнення пам'яті

	return cp;							//повернення стуктури
}
	

int size_file()
{

	FILE *fo;
	char name;
	fo = fopen("data1.txt", "rt");					//функція для знаходження кількості елементів у файлі
	int i = 0;

	while(!feof(fo)){
		fscanf(fo, "%c", &name);
		i++;
	}
	fclose(fo);
	return i;
}

void filePrintf(arrayinfo* cp)
{
	int j = 0;
	FILE *fo;
	fo = fopen("Sort.txt", "w");
	for(int i = 0; i < cp->length; i++)
	{
		while( cp->array_s[i][j] != '\0')
		{
		 	fprintf(fo, "%c", cp->array_s[i][j]);
		 	j++;
		}
		fprintf(fo, " ");
		j = 0;
	}

	
	fclose(fo);
}
