#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "ShellSort.h"

int main()
{
    int size = 0;
    float timeStart, timeStop, timeStart1, timeStop1;

    printf("Enter size of array:");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("Enter again:");
        scanf("%d", &size);
    }

    char mass[size];
    randomizer(mass, size);
    WriteToFile(mass, size, "input.txt");
    timeStart = clock()/(float)CLOCKS_PER_SEC;
    shellSort (mass, size);
    timeStop = clock()/(float)CLOCKS_PER_SEC;
    WriteToFile(mass, size, "output.txt");
printf ("time of Shell sorting: %.10lf\n", (double)(timeStop - timeStart)/CLOCKS_PER_SEC);

 int symbol;
printf("\n\n   Enter Symbol : ");
scanf("%d", &symbol);

    int position;
    timeStart1 = clock()/(float)CLOCKS_PER_SEC;
    position = BinarySearch(symbol, mass, size);
    timeStop1 = clock()/(float)CLOCKS_PER_SEC;
    printf ("time of binary search: %.10lf\n", (double)(timeStop1 - timeStart1)/CLOCKS_PER_SEC);
    if(position != -1)
    {
        printf("Index of searched element is: %i\n", position);
    }
    else
    {
        printf("The element isn't found!\n");
    }
    return 0;

}
