#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"

int main(void)
{
    FILE *txt_file = fopen("Text.txt" , "rt");
    if(txt_file == NULL)
    {
        printf("No such file found");
        return -1;
    }
    else
        printf("File opened\n");

    fseek (txt_file, 0, SEEK_END);
    int length = ftell(txt_file);
	fclose(txt_file);
    printf("Length of file: %i elements\n" , length);

    FILE *txt_file1 = fopen("Text.txt" , "rt");


	char *arr = (char*)malloc(sizeof(char) * length );
    fgets(arr, length, txt_file1);
    fclose(txt_file1);
    getchar();

    printf("Select type of sort:\n 1.Bubble Sort\n 2.Insertion Sort\n 3.Selection Sort\n");
    int type_of_sort = 0;
    scanf("%i" , &type_of_sort);

    if ((type_of_sort == 1) || (type_of_sort == 2) || (type_of_sort == 3) )
    {
clock_t start, stop;
start = clock ();

         switch(type_of_sort)
        {
            case 1:
            BubbleSort ( arr , length);
            break;

            case 2:
            InsertionSort ( arr , length);
            break;

            case 3:
            SelectionSort(length , arr);
            break;
        }

stop = clock();
printf("Time of sorting %.10lf seconds", (double)(stop - start) / CLOCKS_PER_SEC);
return 0;

    }
    else
        {
            printf("Wrong! Select type of sort again!\n");
            return type_of_sort;
        }

    FILE *file = fopen("Tekst_sort.txt","wt");
	int i = 0;
	while(i<length)
	{
		putc((int)arr[i],file);
		i++;
	}
	fclose(file);

    free(arr);
	return 0;

}

