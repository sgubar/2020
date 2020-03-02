#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hidder.h"
int main()
{
    int matrix[3][5];
    int i = 0, j = 0;
    int d;


    for( i = 0; i < 3; i++){
        for( j = 0; j < 5; j++){
            matrix[i][j] = rand() % 55;
      printf("%d\t", matrix[i][j]);
        } printf("\n");
    }


    printf("vvedi chislo = ");
    scanf("%d", &d);
    int b=3; int c=5;
    Umnozenie(matrix, b, c, d);
    
}
