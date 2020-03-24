#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int main()
{
	float TimeStart,TimeStop;
	int size = 0;
	
	char *bubble = loadFile("lab_2.txt" , &size);
	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	bubble_sort(bubble, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;
	printf("\nBubble Sort: %f \n", TimeStop - TimeStart);

	char *insert = loadFile("lab_2.txt" , &size);
	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	insert_sort(insert, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;
	printf("\nInsert Sort: %f \n", TimeStop - TimeStart);

	char *selection = loadFile("lab_2.txt" , &size);
	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	selection_sort(selection, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;
	printf("\nSelection Sort: %f \n", TimeStop - TimeStart);

	recordToFile(bubble, size, "bubble.txt");
	recordToFile(insert, size, "insert.txt");
	recordToFile(selection, size, "selection.txt");
	printf("\nCheck created files:)\n");

	free(bubble);
	free(insert);
	free(selection);

	return 0;
}
