#include "Derevo.h"
#include <stdio.h>
#include <stdlib.h>
derevo* sosdat(int nomer){
    derevo *drug = (struct derevo*) malloc(sizeof(derevo));
    drug->son1=NULL;
    drug->son2=NULL;
    drug->inform=rand();
    drug->nomer=nomer;
    return drug;
}


int vstavka(struct derevo *father, struct derevo *sun){

        if(father->inform>=sun->inform){
            if(father->son1==NULL){
                printf("1\n");
                father->son1=sun;
            }else{
                derevo *tempDerevo;// = (struct derevo*) malloc(sizeof(derevo));
                tempDerevo=father->son1;
                vstavka(tempDerevo,sun);
              //  free(tempDerevo);
            }

        }else{
            if(father->son2==NULL){
                printf("2\n");
                father->son2=sun;
            }else{
                derevo *tempDerevo ;//= (struct derevo*) malloc(sizeof(derevo));
                tempDerevo=father->son2;
                vstavka(tempDerevo,sun);
              //  free(tempDerevo);
            }
        }
}





int obhod(struct derevo *father, int namber){
    namber++;
    printf("  %i          %f        %i\n",namber,father->inform,father->nomer);

    if(father->son1!=NULL){
        obhod(father->son1, namber);
    }
    if(father->son2!=NULL){
        obhod(father->son2, namber);
    }
    namber--;
}
