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
    int size = ftell(txt_file);
	fclose(txt_file);
    printf("Length of file: %i elements\n" , size);

    FILE *txt_file1 = fopen("Text.txt" , "rt");


	char *arr = (char*)malloc(sizeof(char) * size );
    fgets(arr, size, txt_file1);
    fclose(txt_file1);
    getchar();

    printf("Select type of sort:\n 1.Bubble Sort\n 2.Insertion Sort\n 3.Selection Sort\n");
    int type_of_sort = 0;
    scanf("%i" , &type_of_sort);
      //clock_t start = clock();
    if ((type_of_sort == 1) || (type_of_sort == 2) || (type_of_sort == 3) )
    {
clock_t start, stop;
unsigned long t;
start = clock ();

         switch(type_of_sort)
        {
            case 1:
            BubbleSort ( arr , size);
            break;

            case 2:
            InsertionSort ( arr , size);
            break;

            case 3:
            SelectionSort(size , arr);
            break;
        }

     /*  struct tm *ptr;
time_t It;
It = time(NULL);
ptr = localtime(&It);
printf(asctime(ptr));
return 0;*/

SelectionSort(size , arr);
stop = clock();
printf("Time of sorting %f seconds", (stop - start) / CLK_TCK);
return 0;




    /* unsigned int start_time =  clock(); // начальное время
    SelectionSort(size , arr);// здесь должен быть фрагмент кода, время выполнения которого нужно измерить
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time_selection = end_time - start_time; // искомое время*/

       /* clock_t end = clock();
        float time1 = end - start;
        printf("Time sorting: %0.10f\n", time1/CLOCKS_PER_SEC);*/


	/*SelectionSort(length , buffer);
	clock_t theEnd0 = clock();
	SelectionSort(length , buffer);
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);*/

    }
    else
        {
            printf("Wrong! Select type of sort again!\n");
            return type_of_sort;
        }

    FILE *file = fopen("Tekst_sort.txt","wt");
	int i = 0;
	while(i<size)
	{
		putc((int)arr[i],file);
		i++;
	}
	fclose(file);

    free(arr);
	return 0;

}
