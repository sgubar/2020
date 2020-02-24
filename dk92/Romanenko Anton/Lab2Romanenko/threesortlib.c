//
// Created by anton on 24.02.2020.
//

#include "threesortlib.h"

char *randomLetterArray(int size)
{
    char *array = (char *)malloc(sizeof(char) * size);

    if (array != NULL)
    {
        srand(time(NULL));
        int tmp;
        for (int i = 0; i < size; ++i)
        {
            if (i % 2 == 0)
            {
                tmp = rand() % (90 - 65) + 65;
            }
            else
            {
                tmp = rand() % (122 - 97) + 97;
            }

            array[i] = (char)tmp;
        }
    }

    return array;
}

void printArray(char *mass, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%c", mass[i]);
    }

    printf("\n");
}

void deleteArray(char *arrayArr)
{
    free(arrayArr);
}

void printInFile(char *letterArray, int sizeOfArray, char *name)
{
    FILE *rezult_file;
    if (rezult_file = fopen(name, "w") == NULL)
    {
        printf("ERROR!\n");
    }
    else
    {
        rezult_file = fopen(name, "w");
        for (int i = 0; i < sizeOfArray; ++i)
        {
            fprintf(rezult_file, "%c", letterArray[i]);
        }

        fclose(rezult_file);
    }

}