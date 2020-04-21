#include <stdio.h>
#include "dk_tools.h"
void FirstMatrix(int x, int matrix[10][10]){

    int e = 0;
    int i,j;
    printf("Fill the array\n");
    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
        e++;
        printf("Enter the %i element of the array: \n", e);
        scanf("%d", &matrix[i][j]);
        }
    }
}

void resultOfmultiplication(int x, int matrix1[10][10],int matrix2[10][10],int result_matrix[10][10]){

     int i,j,k;

    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
        	result_matrix[i][j] = 0;
                for(k = 0; k < x; k++){
                    result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
        }
    }

}

void print(int x, int result_matrix[10][10]){
int i,j;
printf("Array multiplication result:\n");
for(i = 0; i < x; i++){
for(j = 0; j < x; j++){
printf("%i ", result_matrix[i][j]);
}
printf("\n");
}

}
