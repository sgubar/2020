#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"


void BubbleSort (char buffer[], long length)
{
    int theOut;
	for (theOut = 0; theOut < length; theOut ++)
	{
		int theIn;
		for (theIn = 0; theIn < length - 1 ; theIn ++)
		{
			if (buffer[theIn + 1] < buffer[theIn])
			{
				char theTmp = buffer[theIn];
				buffer[theIn] = buffer[theIn + 1];
				buffer[theIn + 1] = theTmp;
			}
		}
	}
}


void InsertionSort ( char buffer[] , long length)
{
    int theOut;

	for (theOut = 1; theOut < length; theOut ++)
	{
		char theTmp = buffer[theOut];
		int theIn = theOut;
		while (theIn > 0 && (buffer[theIn-1] >= theTmp))
		{
			buffer[theIn] = buffer[theIn - 1];
			-- theIn;
		}
			buffer[theIn] = theTmp;
	}
}

void SelectionSort(long length , char buffer[])
{
    int theOut;
	for (theOut = 0; theOut < length - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;
		for (theIn = theOut + 1;theIn < length; theIn ++)
		{
			if (buffer[theIn]<buffer[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		char theTmp = buffer[theOut];
		buffer[theOut] = buffer[theMinIndex];
		buffer[theMinIndex] = theTmp;
	}
}
void SortSelect (int type_of_sort, char buffer[], long length){
if ((type_of_sort == 1) || (type_of_sort == 2) || (type_of_sort == 3) )
    {
        clock_t start = clock();


         switch(type_of_sort)
        {
            case 1:
            BubbleSort ( buffer , length);
            break;

            case 2:
            InsertionSort ( buffer , length);
            break;

            case 3:
            SelectionSort(length , buffer);
            break;
        }
        clock_t end = clock();
        float time1 = end - start;
        printf("Time sorting: %0.10f\n", time1/CLOCKS_PER_SEC);

    }
    else
        {
            printf("Wrong! Select type of sort again!\n");
            //return type_of_sort;
        }
}
   void inPut( long length, char buffer[]){
       int i = 0;
      FILE *file  = fopen("Tekst_sort.txt","wt");
       	while(i<length)
	{
		putc((int)buffer[i],file);
		i++;
	}
	fclose(file);

    free(buffer);
   }
  void Open(){
    FILE *txt_file = fopen("Text.txt", "rt");
    if(txt_file == NULL)
   {
        printf("No such file found");


    }
    else{
        printf("File opened\n");
        fseek (txt_file, 0, SEEK_END);
    int length = ftell(txt_file);
	fclose(txt_file);
    printf("Length of file: %i elements\n" , length);
    FILE *txt_file1 = fopen("Text.txt" , "rt");
	char *buffer = (char*)malloc(sizeof(char) * length );
    fgets(buffer, length, txt_file1);
    fclose(txt_file1);
    int type_of_sort = 0;
    printf("Select type of sort:\n 1.Bubble Sort\n 2.Insertion Sort\n 3.Selection Sort\n");
     scanf("%i" , &type_of_sort);
    SortSelect (type_of_sort,  buffer,  length);
    inPut( length, buffer);
    }
   }
