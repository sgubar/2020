#include "tools.h"

int getInt(char *label)
{
    char *p, s[100];
    int result;
    if (label != NULL || label != "")
    {
        printf(label);
    }
    while (fgets(s, sizeof(s), stdin))
    {
        result = strtol(s, &p, 10);

        if (p == s || *p != '\n')
        {
            printf("Please enter an integer: \n");
            continue;
        }
        return result;
    }
}

float getFloat(char *label)
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
        if (p == s || *p != '\n' || result < 1)
        {
            printf("Please enter a float greater than 0\n");
        }
        else
            return result;
    }
}