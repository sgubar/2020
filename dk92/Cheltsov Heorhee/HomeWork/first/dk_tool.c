//
// Created by chelt on 20.04.2020.
//
#include <stdio.h>
#include "dk_tool.h"

int matrixminus(int mata[][4], int matb[][4]){
    int res[4][4];
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            res[x][y] = mata[x][y] - matb[x][y];
            printf("%d ", res[x][y]);
        }
        printf("\n");
    }
    return 1;
}