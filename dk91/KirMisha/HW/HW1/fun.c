#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int otnimani(int A[3][5], int B[3][5], int C[3][5], int n, int m)
{
    for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
     C[i][j] = A[i][j] - B[i][j];
     printf("%d\t", C[i][j]);
    }
    printf("\n");
    }
}
