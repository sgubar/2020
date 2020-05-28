#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int string_compare(const char *str1, const char *str2)
{
    int length2 = strlen(str2);
    int length1 = strlen(str1);
    int match_c = 0;
    int result = 0;

    if(length1 > length2)
    {
    for(int i = 0; i < length1 - length2 + 1; i++)
    {
        for(int j = 0; j < length2; j++)
        {
            if(str2[j] == str1[j + i])
            {
                match_c++;
                if(match_c == length2)
                {
                    result++;
                    match_c = 0;
                }
            }
            else
            {
                match_c = 0;
            }
        }
    }
    return result;
    }
    else
    {
        return -1;
    }
}
