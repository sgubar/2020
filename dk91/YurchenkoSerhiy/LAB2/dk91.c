#include "dk91.h"
#include <time.h>

int Create(int anArray[], int aSize)
{
    FILE * fo;
     fo = fopen("text.txt", "wt");
     for(int i = 0; i < aSize; i++){
            anArray[i] = rand() % 10000;
      printf("%d\t", anArray[i]);
      fprintf(fo, "%d\t", anArray[i]);
        }printf("\n");
        fclose(fo);
}

int print(int anArray[], int aSize)
{
     for(int i = 0; i < aSize; i++){
      printf("%d\t", anArray[i]);
        }
        printf("\n");
}

void bubbleSort(int anArray[], int aSize)
{
    clock_t time, start, stop;
    start = clock();
	for (int theOut = aSize - 1; theOut > 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
	stop = clock();
    time = stop - start;
    printf("%f ", (double)time/CLOCKS_PER_SEC);
}

void selectionSort(int anArray[], int aSize)
{
    clock_t time, start, stop;
    start = clock();
	for (int theOut = 0; theOut < aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < aSize; theIn ++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
	stop = clock();
    time = stop - start;
    printf("%f ", (double)time/CLOCKS_PER_SEC);
}

void insertionSort(int anArray[], int aSize)
{
    clock_t time, start, stop;
    start = clock();
	for (int theOut = 1; theOut < aSize; theOut ++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;

		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}

		anArray[theIn] = theTmp;
	}
	stop = clock();
    time = stop - start;
    printf("%f ", (double)time/CLOCKS_PER_SEC);
}
