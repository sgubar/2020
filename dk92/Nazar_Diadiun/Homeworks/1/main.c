//
//  main.c
//  Homework1
//
//  Created by Nazar Diadiun on 22.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include <stdio.h>
#include "dk_tools.h"

int main(int argc, const char * argv[])
{
    int firstMatrix[3][3], secondMatrix[3][3];
    MatrixFill(firstMatrix, secondMatrix);
    
    matrixProcess(firstMatrix, secondMatrix);
    return 0;
}
