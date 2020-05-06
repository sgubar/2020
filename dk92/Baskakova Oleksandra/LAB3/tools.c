#include "tools.h"

unsigned int getUnsignedInt(char* label)
{
    char *p, s[100];
    int result;
    printf(label);
    while (fgets(s, sizeof(s), stdin))
    {
        result = strtoul(s, &p, 10);

        if (p == s || *p != '\n')
        {
            printf("Please enter an unsigned integer: \n");
            continue;
        }
                return result;
    }
}

void fprintResult(FILE *file, char label[], int *result, int size)
{
    fputs(label, file);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d: %d\n", i, result[i]);
    }
}

void *createArray(int size)
{
    int *array = (int)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10000;
    }
    return array;
}

int linearSearch(int *array, int size, int element)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == element)
            return i;
    }
    return -1;
}