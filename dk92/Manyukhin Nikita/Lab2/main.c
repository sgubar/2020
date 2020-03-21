#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "sortTools.h"

int main()
{
    int aSize;
    printf("Max Size from 25000 to 100000\nEnter Size of Array: \n");
    do
    {
        scanf("%d", &aSize);
        if (aSize < 25000 || aSize > 100000) printf("Error! Enter another :\n");
    }while (aSize < 25000 || aSize > 100000);

    int *aArray = (int *) malloc(sizeof(int) * aSize);
    if(aArray == 0)
	{
		printf("ERROR\n");
		return 1;
	}

    FILE *file;
    file = fopen ("Result.txt", "w");
    if(file == 0)
	{
		printf("File not created!\n");
		free(aArray);
		return 2;
	}
	sortArray(aArray, aSize, file);

	fflush(file);
	fclose(file);
    free(aArray);
    return 0;
}
