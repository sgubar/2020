#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int row_1, col_1;
    int row_2, col_2;

    printf("Enter the number of rows of the first matrix: \n");
    scanf("%d", &row_1);

    printf("Enter the number of columns of the first matrix: \n");
    scanf("%d", &col_1);

    printf("Enter the number of rows of the second matrix: \n");
    scanf("%d", &row_2);

    printf("Enter the number of columns of the second matrix: \n");
    scanf("%d", &col_2);


    if(col_1 != col_2 || row_1 != row_2){

        printf("Matrix summation impossible");

    }else{

    int *matrix_1 = (int*)malloc(row_1*col_1 * sizeof(int));
    int *matrix_2 = (int*)malloc(row_2*col_2 * sizeof(int));



    printf("Enter the elements of the first matrix\n"); //ВВОД 1 МАТРИЦЫ

    for(int i=0; i < row_1; i++ ){
        for(int j=0; j < col_1; j++){

            printf("a[%d][%d] = ", i,j);
            scanf("%d", (matrix_1 + i*col_1 + j));
        }
    }

    printf("\nEnter the elements of the second matrix\n"); //ВВОД 2 МАТРИЦЫ
     for(int i=0; i < row_2; i++ ){
        for(int j=0; j < col_2; j++){

            printf("a[%d][%d] = ", i,j);
            scanf("%d", (matrix_2 + i*col_2 + j));
        }
    }

    matrixsum(matrix_1, matrix_2, row_1, col_1);
    vivodmatrix(matrix_1, row_1, col_1);

    }
    return 0;
}
