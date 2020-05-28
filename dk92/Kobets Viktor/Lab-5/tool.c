#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

unsigned int get_natural_int(char *label)
{
    char *p, s[100];
    int result;
    if (label != NULL || label != "")
    {
        printf(label);
    }
    while (fgets(s, sizeof(s), stdin))
    {
        result = strtoul(s, &p, 10);

        if (p == s || *p != '\n' || result < 1)
        {
            printf("Please enter an unsigned integer: \n");
            continue;
        }
        return result;
    }
}

float get_float(char *label)
{
    char *p, s[100];
    float result;
    if (label != NULL || label != "")
    {
        printf(label);
    }
    while (fgets(s, sizeof(s), stdin))
    {
        result = strtof(s, &p);

        if (p == s || *p != '\n')
        {
            printf("Please enter an float: \n");
            continue;
        }
        return result;
    }
}