#include "dk91.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    FILE *aFile = fopen("1.txt", "r");

    int check = bracketBallanceCheck(aFile);

    if(check == 1)
    {
        printf("Brackets in file didn't match.\n");
    }

    if(check == 0)
    {
        printf("Brackets in file match.\n");
    }

    if(check == 2)
    {
        printf("\nFile doesn't exist.\n");
    }
    fclose(aFile);
    return 0;
}
