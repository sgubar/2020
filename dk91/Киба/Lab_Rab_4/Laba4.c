#include "Laba4.h"
#include <stdio.h>
#include <stdlib.h>


void rendomm(struct el *n, int kol){
    for(int i=0;i<kol;i++){
        int ii=i-1;
        int iii=i+1;
        if(ii<0)ii=kol;
        if(iii==kol)iii=0;
        n[i].pred=&n[ii];
        n[i].element=rand();///////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
       // n[i].element=i+10;//////////////////////////////////////////////////////////
        n[i].next=&n[iii];
    }
    n[0].element=0;
}




int deleteE(struct el *n, int kol,int udal){
    int temp=0;
    temp=n[0].next;
    while(udal>1){
        temp=((el*)temp)->next;
        udal--;
    }
    int *pred= ((el*)temp)->pred;
    int *sled=((el*)temp)->next;
    ((el*)pred)->next=sled;
    ((el*)sled)->pred=pred;
 return 1;
}







void vivod(struct el *n,int kol){
    int temp = n[0].next;
   //     printf("%i ",n[0].element);
    for(int i=1;i<kol;i++){
        printf("%i ",((el*)temp)->element,i);
        temp=((el*)temp)->next;

    }
    printf("\n");
}


