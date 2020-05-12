#include <stdio.h>
#include "Bsearch.h"

int binsearch(char array[], char n, int l, int size){
    int r = size-1;
    int center = (l + r)/2;
    int serchInd = -1;

    if(size < 4){
        if(n == array[0]){
            serchInd = 0;
        }
        else if(n == array[1]){
            serchInd = 1;
        }
        else if(n == array[2]){
            serchInd = 2;
        }
        else{
            printf("Error 404 Not Found");
            return serchInd;
        }
    }else{
        while (l <= r)
        {
            center = (l + r)/2;
            if (n == array[center]) {
                serchInd = center;
                break;
            }
            if (n < array[center])
                r = center - 1;
            else
                l = center + 1;
        }
        if(serchInd == -1){
            printf("Error 404 Not Found");
        }
    }
    return serchInd + 1;
}