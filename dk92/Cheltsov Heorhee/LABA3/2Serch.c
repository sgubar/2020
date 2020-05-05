//
// Created by chelt on 04.05.2020.
//

#include <stdio.h>
#include "2Serch.h"

int midle(int left, int right){
    int center;

    center = (left + right)/2;

    return center;
}


int binarSerch(char SerchArray[], char inChar, int sizeSerch){
    int leftInd = 0;
    int rightInd = sizeSerch-1;
    int centerInd = midle(0, sizeSerch);
    int serchInd = -1;

    if(sizeSerch < 4){
        if(inChar == SerchArray[0]){
            serchInd = 0;
        }
        else if(inChar == SerchArray[1]){
            serchInd = 1;
        }
        else if(inChar == SerchArray[2]){
            serchInd = 2;
        }
        else{
            printf("Error 404 Not Found");
            return serchInd;
        }
    }else{
        while (leftInd <= rightInd)
        {
            centerInd = midle(leftInd, rightInd);
            if (inChar == SerchArray[centerInd]) {
                serchInd = centerInd;
                break;
            }
            if (inChar < SerchArray[centerInd])
                rightInd = centerInd - 1;
            else
                leftInd = centerInd + 1;
        }
        if(serchInd == -1){
            printf("Error 404 Not Found");
        }
    }
    return serchInd + 1;
}

