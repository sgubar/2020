#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

//https://onedrive.live.com/view.aspx?resid=D1785C298F1B017B!12316&ithint=file%2cxlsx&authkey=!ADc658mdQFL5PAM
//var 4

int vvod(int a, int b);
int fillmat(int t, int m[][4]);
int printmat(int p[][4]);

int main() {

    int type1;
    int type2;

    int mata[4][4];
    int matb[4][4];

    printf("Chose type of enter matrix \n 1) Auto \n 2) Manual \n");
    type1 = vvod(1, 2);
    if(type1 == 1){
        printf("1) Auto \n");
    }else{
        printf("2) Manual \n");
    }

    fillmat(type1, mata);
    fillmat(type1, matb);

    printmat(mata);
    printmat(matb);

    printf("Chose type of subtract matrix \n 1) A|| - B|| \n 2) B|| - A|| \n");
    type2 = vvod(1,2);

    if(type2 == 1){
        matrixminus(mata, matb);
    } else{
        matrixminus(matb, mata);
    }

    return 0;
}

int vvod(int a, int b){
    char buf[32];
    int pass = 0;
    int s;

    do{
        fgets(buf, 31, stdin);
        if(sscanf(buf, "%d", &s) != 1){
            printf("try again \n");
            pass = 0;
        }
        else{
            if( (s >= a) && (s <= b)){
                pass = 1;
                printf("OK %d \n",s);
            } else{
                printf("try again \n");
            }
        }
    }while(pass != 1);
    return s;
}

int fillmat(int t, int m[][4]){

    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            if(t == 1){
                m[x][y] = rand() % 100;
            }
            else{
                printf("[%d][%d]", x, y);
                m[x][y] = vvod(0, 99);
            }
        }
    }

}


int printmat(int p[][4]){
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            printf("%d ", p[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}