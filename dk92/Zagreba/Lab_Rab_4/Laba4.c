#include "Laba4.h"
#include <stdio.h>
#include <stdlib.h>


void rendomm(struct el *n, int kol, int rendom){
    srand(rendom);
    for(int i=0;i<kol;i++){
        int ii=i-1;
        int iii=i+1;
        if(ii<0)ii=kol;
        if(iii==kol)iii=0;
        n[i].pred=&n[ii];
        n[i].element=rand();
        n[i].next=&n[iii];
    }
}


int deleteE(struct el *n,int kol){    //Вопрос почему не заработало   int deleteE(struct el *n,int *kol)
    int problem=kol;
    int element1=kol-1;
    if(element1<0)element1=element1+kol;
    int pretudu_element=element1-1;
    if(pretudu_element<0)pretudu_element=pretudu_element+kol;
    int sled_element=element1+1;
    if(sled_element==kol)sled_element=sled_element-problem;
    n[sled_element].pred=&n[pretudu_element];
    n[pretudu_element].next=&n[sled_element];
    kol=kol-1;
    return kol;
}


void vovod(struct el *n,int kol){

    for(int i=0;i<kol;i++){
        int ii=i-1;
        if(ii<0)ii=kol-1;
        int temp = n[ii].next;
        printf("%i,",((el*)temp)->element);
    }
    printf("\n");
}


int loneinost(struct el *n, int kol){
    while(kol>2){
        kol=deleteE(n,kol);
        vovod(n,kol);
    }
    return kol;
}
