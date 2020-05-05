#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
#include <time.h>

void ShellSort(char *aArray, long  length)
{
	int theIn, H = 1;

	while(H <= length / 3)
	{
		H = H * 3 + 1;
	}

	while(H > 0)
	{
		for(int theOut = H; theOut < length; theOut++)
		{
			int tmp = aArray[theOut];
			theIn = theOut;

			while(theIn > H - 1 && aArray[theIn - H] >= tmp)
			{
				aArray[theIn] = aArray[theIn - H];
				theIn -= H;
			}
			aArray[theIn] = tmp;
		}
		H = (H - 1) / 3;
	}
}

int binarysearch(char *aArray, long length, char val)
{
int middle, lower = 0, upper = length - 1;
while(lower <= upper)
{
	middle = (lower + upper) / 2;

	if(aArray[middle] == val)
	{
		return 0;
	}

	else if(aArray[middle] < val)
	{
		lower = middle + 1;
	}

	else
	{
		upper = middle - 1;
	}
}
return -1;
}

void searchArray(char *aArray, long length)
{


	char val, result;
	do{
		printf("\nEnter value to search: ");
		scanf("%x", &val);
	}while(val < 0);

    printf("Binary search started\n");
    clock_t start = clock();
	result = binarysearch(aArray, length,  val);
	clock_t end = clock();
    float time1 = end - start;
    printf("Time sorting: %0.10f\n", time1/CLOCKS_PER_SEC);
	printf("Binary search finished\n");


	if(result == 0)
	{
		printf("Founded!\n");
	}
	else
	{
		printf("Not founded\n");
	}
}



int mainProcess(){

    FILE *txt_file = fopen("Text.txt" , "rt");
    Open();
    fseek (txt_file, 0, SEEK_END);
    long length = ftell(txt_file);
	fclose(txt_file);
    printf("Length of file: %i elements\n" , length);
    FILE *txt_file1 = fopen("Text.txt" , "rt");
	char *aArray = (char *) malloc(sizeof(char) * length);
    fgets(aArray, length, txt_file1);
   // fclose(txt_file1);
   printf("Shellsort started\n");
    clock_t	first = clock();
	 ShellSort( aArray,  length);
	 clock_t second = clock();
	float time = second - first;
        printf("Time sorting: %0.10f\n", time/CLOCKS_PER_SEC);
     searchArray(aArray, length);
	inPut( length,  aArray);
    }

     void inPut( long length, char *aArray){
       int i = 0;
      FILE *file  = fopen("Tekst_sort.txt","wt");
       	while(i<length)
	{
		putc((int)aArray[i],file);
		i++;
	}
	fclose(file);

    free(aArray);
   }

    void Open(){
    FILE *txt_file = fopen("Text.txt", "rt");
    if(txt_file == NULL){
        printf("No such file found");
        exit(0);
    }
    else
        printf("File opened\n");

    }

