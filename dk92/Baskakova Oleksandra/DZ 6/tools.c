#include "tools.h"

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

 int get_int(char *label)
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
