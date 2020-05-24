#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include "dk_tools.h"

int main(int argc, char const *argv[])
{
    int nLen = getUnsignedInt("write matrix [n] length \n");
    int mLen = getUnsignedInt ("write matrix [m] length \n");
    printf("write matrix elements \n");
    Matrix matrix = readMatrix(nLen, mLen);
    int multiplicator = getInt ("write matrix multiplicator");
    Matrix resultMatrix = MulMatrixToNumber(matrix, multiplicator);
    printMatrix(resultMatrix);
    free(matrix.elements);
    return 0;
}