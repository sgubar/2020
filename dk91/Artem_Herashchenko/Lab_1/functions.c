#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"


int factorial(int x){
int a=1;

if(x>=0){

for(int i=1; i<=x; i++){
    a*=i;
    }
return  a;
}else return 0;

}


float sum(int x, int y){
    float sum=0;

    for(int i=0;i<=x; i++){
        sum+=factorial(y+i);
    }
return sum;
}
