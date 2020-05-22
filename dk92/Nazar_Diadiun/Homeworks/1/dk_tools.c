//
//  dk_tools.c
//  Homework1
//
//  Created by Nazar Diadiun on 22.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include "dk_tools.h"

void matrixProcess (int firstMatrix[3][3], int secondMatrix[3][3])
{
    int resultMatrix[3][3];
    for(int i = 0; i < 3; i++){
        for(int b = 0; b < 3; b++){
            resultMatrix[i][b] = firstMatrix[i][b] - secondMatrix[i][b];
        }
    }
    
    printf("Result matrix: \n");
    for(int i = 0; i < 3; i++){
        for(int b = 0; b < 3; b++){
            printf("%d, ", resultMatrix[i][b]);
        }
        printf("\n");
    }
}

void MatrixFill(int firstMatrix[3][3], int secondMatrix[3][3])
{
    int matrixCount = 0;
    
fillMatrix:
    switch (matrixCount) {
        case 0:
        printf("Fill First Matrix with values \n");
            for(int i = 0; i < 3; i++){
                for(int b = 0; b < 3; b++){
                    printf("Enter the element for [%d][%d] position:", i, b);
                    scanf("%d \n", &firstMatrix[i][b]);
                }
            }
            break;
        case 1:
        printf("Fill Second Matrix with values \n");
            for(int i = 0; i < 3; i++){
                for(int b = 0; b < 3; b++){
                    printf("Enter the element for [%d][%d] position:", i, b);
                    scanf("%d \n", &secondMatrix[i][b]);
                }
            }
            break;
            
        default:
            break;
    }
    
    if(matrixCount == 0){
    matrixCount = 1;
    goto fillMatrix;
    }
}
