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


float sum(int C, int A){
    float sum=0;

    for(int D=0;D<=C; D++){
        sum+=factorial(A+D);
    }
return sum;
}
