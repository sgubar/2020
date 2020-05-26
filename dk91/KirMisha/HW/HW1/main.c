#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main()
{
int n = 3;
int m = 5;
int A[n][m];
int B[n][m];
int C[n][m];

    for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      A[i][j] = rand() % 200;
      printf("%d\t", A[i][j]);
    }
    printf("\n");
    }
    printf("\n");
    for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
      B[i][j] = rand() % 100;
      printf("%d\t", B[i][j]);
    }
    printf("\n");
    }
    printf("\n");
otnimani(A, B, C, n, m);

}
