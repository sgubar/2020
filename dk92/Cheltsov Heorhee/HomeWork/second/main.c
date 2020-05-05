#include <stdio.h>
#include "dk_line.h"
#include <math.h>

int vvod();

int main() {

    int x;
    int y;
    int S;
    int pass = 0;

    do{

    printf("Bild rectangle at two points \n Enter cordenate \nA(x, y)\n x=");

    x = vvod();
    printf(" y=");
    y = vvod();
    Point A = {x, y};

    printf("Enter cordenate  \nC(x, y)\n x=");

    x = vvod();
    printf(" y=");
    y = vvod();
    Point C = {x, y};

    Figura *prymoug = createFiguruAndPoints(&A, &C);
    printFigura(prymoug);

    S = sqea(prymoug);
    printf("S = %d \n", S);

    destroyFigura(prymoug);

    printf("Exit = 0, Restart = ant num \n");
    pass = vvod();

    }while(pass != 0);

    return 0;
}

int vvod(){
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
            pass = 1;
            printf("OK %d \n", s);
        }
    }while(pass != 1);
    return s;
}
