#include <stdio.h>

#include "threesortlib.h"
#include "Sort.h"
#define SIZE 9

int main()
{
    char file1[]= "bubbleSort.txt";
    char file2[]= "chooseSort.txt";
    char file3[]= "pasteSort.txt";

    char *bubbleLetter= randomLetterArray(SIZE);
    char *pasteLetter= randomLetterArray(SIZE);
    char *chooseLetter= randomLetterArray(SIZE);

    printArray(bubbleLetter, SIZE);
    printArray(pasteLetter, SIZE);
    printArray(chooseLetter, SIZE);

    bubbleLetter = bubbleSort(bubbleLetter, SIZE);
    printInFile(bubbleLetter, SIZE, file1);

    chooseLetter = chooseSort(chooseLetter, SIZE);
    printInFile(chooseLetter, SIZE, file2);

    pasteLetter = pasteSort(pasteLetter, SIZE);
    printInFile(pasteLetter, SIZE, file3);

    deleteArray(pasteLetter);
    deleteArray(chooseLetter);
    deleteArray(bubbleLetter);

    return 0;
}
