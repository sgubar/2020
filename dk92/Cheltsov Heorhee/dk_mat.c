//
// Created by chelt on 23.02.2020.
//

#include "dk_mat.h"


float cube(float x) {
    float rezult = 0;

    rezult = x*x*x;

    return rezult;
}

float mod(float in){
    float rezult = 0;
    if(in < 0){
        rezult = in*(-1);
        return rezult;
    } else{
        return in;
    }
}

float powertwo(int x){
    float rezult = 0;
    int i;

    if(x == 0){
        rezult = 1;
    }
    else{
        rezult = 1;
        for(i = 1; i <= x; i++){
            rezult = rezult * 2;
        }
    }

    return rezult;
}

float sum(int it){

    int result = 0;

    for (int i = 0; i <= it; i ++)
    {
        result += powertwo(i);
    }

    return result;

}
