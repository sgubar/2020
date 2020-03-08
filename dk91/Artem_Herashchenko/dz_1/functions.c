#include <stdio.h>
#include <stdlib.h>

void matrixsum(int *matrix_1, int *matrix_2, int row_1, int col_1){

 for(int i=0; i < row_1; i++){                                                             //СУММА МАТРИЦ
        for(int j=0; j < col_1; j++){
            *(matrix_1 + i*col_1 + j) = *(matrix_1 + i*col_1 + j)+ *(matrix_2 + i*col_1 + j);
        }
    }
    return matrix_1;
}

void vivodmatrix(int *matrix_1, int row_1, int col_1){
 for(int i=0; i < row_1; i++ ){                                         //ВЫВОД МАТРИЦЫ
        for(int j=0; j < col_1; j++){


            printf("%d ", *(matrix_1 + i*col_1 + j));
        }
        printf("\n");
    }
}
