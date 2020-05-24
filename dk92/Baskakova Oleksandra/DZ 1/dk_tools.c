#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

unsigned int getUnsignedInt(char *label)
{
    char *p, s[100];
    int result;
    printf(label);
    while (fgets(s, sizeof(s), stdin))
    {
        result = strtoul(s, &p, 10);

        if (p == s || *p != '\n' || result < 0)
        {
            printf("Please enter an unsigned integer: \n");
            continue;
        }
        return result;
    }
}

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

Matrix readMatrix(int nLen, int mLen)
{
    Matrix matrix;
    matrix.elements = (int **)malloc(nLen * sizeof(int *));
    matrix.nLen = nLen;
    matrix.mLen = mLen;

    for (int n = 0; n < nLen; n++)
    {
        matrix.elements[n] = (int *)malloc(mLen * sizeof(int));
        for (int m = 0; m < mLen; m++)
        {
            matrix.elements[n][m] = getInt("");
        }
    }
    return matrix;
}

Matrix MulMatrixToNumber(Matrix matrix, int num)
{
    for (int n = 0; n < matrix.nLen; n++)
    {
        for (int m = 0; m < matrix.mLen; m++)
        {
            matrix.elements[n][m] *= num;
        }
    }
    return matrix;
}

void printMatrix(Matrix matrix)
{
    for (int n = 0; n < matrix.nLen; n++)
    {
        for (int m = 0; m < matrix.mLen; m++)
        {
            printf("%d ", matrix.elements[n][m]);
        }
        printf("\n");
    }
}
