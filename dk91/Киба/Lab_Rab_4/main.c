#include <stdio.h>
#include <stdlib.h>
#include "Laba4.h"

int main()
{   int kol=0;
    printf("Vvedi kolvo elementov\n");
    scanf("%i", &kol);
    kol++;

    el *n=(struct el*)malloc(sizeof(el)*kol);
    rendomm(n,kol);
    int udal=kol-1;
    while(kol>3){
        do{
            if(udal<=0)udal=udal+kol;
            if(udal>kol)udal=udal-kol-1;
        }while(udal>kol||udal<=0);
        printf("     %i udal\n",udal);
        printf("     %i kol\n",kol-1);
        deleteE(n,kol,udal);
        kol--;
        vivod(n,kol);
        udal=udal-3;
    }

    return 0;
}
