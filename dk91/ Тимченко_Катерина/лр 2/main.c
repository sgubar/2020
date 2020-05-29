#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int main()
{
	float TimeStart,TimeStop;
	int size = 0;

	char *bubble = loadFile("lab_2.txt" , &size);
	TimeStart = clock();
	bubble_sort(bubble, size);
	TimeStop = clock();
	printf("\nBubble Sort: %f \n", (TimeStop - TimeStart)/(float)CLOCKS_PER_SEC);

	char *insert = loadFile("lab_2.txt" , &size);
	TimeStart = clock();
	insertion_sort(insert, size);
	TimeStop = clock();
	printf("\nInsert Sort: %f \n", (TimeStop - TimeStart)/(float)CLOCKS_PER_SEC);

	char *selection = loadFile("lab_2.txt" , &size);
	TimeStart = clock();
	selection_sort(selection, size);
	TimeStop = clock();
	printf("\nSelection Sort: %f \n", (TimeStop - TimeStart)/(float)CLOCKS_PER_SEC);

	recordToFile(bubble, size, "bubble.txt");
	recordToFile(insert, size, "insert.txt");
	recordToFile(selection, size, "selection.txt");

	free(bubble);
	free(insert);
	free(selection);

	return 0;
}

