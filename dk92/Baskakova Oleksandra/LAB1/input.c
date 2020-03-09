#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include <stdbool.h>

float getFloat()
{
    char *p, s[100];
    float result;

    while (fgets(s, sizeof(s), stdin))
    {
        result = strtof(s, &p);
        if (*p == 'e')
            exit(0);
        if (p == s || *p != '\n')
        {
            printf("Please enter an float: or press e to exit\n");
        }
        else
            return result;
    }
}

unsigned int getUnsignedInt()
{
    char *p, s[100];
    int result;

    while (fgets(s, sizeof(s), stdin))
    {
        result = strtoul(s, &p, 10);

        if (p == s || *p != '\n')
        {
            printf("Please enter an integer: \n");
            continue;
        }
        if (result <= 0)
        {
            printf("B should be greater then zero\n");
            continue;
        }
        return result;
    }
}
