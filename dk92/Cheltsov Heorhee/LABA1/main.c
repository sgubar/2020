#include <stdio.h>
#include "dk_mat.h"

float rechenie(int a, float b, float c);

int main() {
    int pass = 0;

    int A;
    float B;
    float C;

    char buf[32];

    printf("Enter Variable:\n");
    printf("integer A > 0 \n");
    do{
        fgets(buf, 31, stdin);
        if(sscanf(buf, "%d", &A) != 1){
            printf("try again \n");
            pass = 0;
        }
        else{
            if(A >= 0){
                pass = 1;
            }
            else{
                printf("try again \n");
                pass = 0;
            }
        }

    }while(pass != 1);

    printf("A = %d \n", A);



    printf("float B = \n");
    do{
        fgets(buf, 31, stdin);
        if(sscanf(buf, "%F", &B) != 1){
            printf("try again \n");
            pass = 0;

        }
        else {
            pass = 1;
        }
    }while(pass != 1);

    printf("B = %f \n", B);




    printf("float C != 0 \n");
    do{
        fgets(buf, 31, stdin);
        if(sscanf(buf, "%f", &C) != 1){
            printf("try again \n");
            pass = 0;
        }
        else {
            if (C != 0) {
                pass = 1;
            } else {
                printf("try again \n");
                pass = 0;
            }
        }
    }while(pass != 1);

    printf("C = %f \n", C);

    printf("Start calculating...\n");

//    printf("---TEST dk_mat--- \n");
//    printf("4^3 = %f \n", cube(4));
//    printf("3^3 = %f \n", cube(3));
//    printf("mode(-1) = %f \n", mod(-1));
//    printf("mode(1) = %f \n", mod(1));
//    printf("2^0 = %f \n", powertwo(0));
//    printf("2^1 = %f \n", powertwo(1));
//    printf("2^2 = %f \n", powertwo(2));



    printf("Result = %f", rechenie(A, B, C));

    return 0;
}


float rechenie(int a, float b, float c){
    float result = 0;

    if( (a*b+c) == 0){
        result = 0;
    } else{
        float in = (a*c)-b;
        //printf("in = %f \n", in);
        float mode = mod(in);
        //printf("mode = %f \n", mode);
        float cub = cube(c);
        //printf("cub = %f \n", cub);
        float suma = sum(a);
        //printf("sum = %f \n", suma);
        result = (mode/cub)*suma;
    }
    return result;
}

