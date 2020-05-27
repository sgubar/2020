#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
tree* creat(){
    tree *drug = (struct tree*) malloc(sizeof(tree));
    drug->son=NULL;
    drug->Spiert=NULL;
    drug->inform=rand()%10;
    return drug;
}


int vstavka(struct tree *perent, struct tree *sun){
        if(perent->inform>=sun->inform){
                if(perent->son== NULL){
                    printf("1\n");
                    perent->son=sun;
                }else{
                    tree *tempDerevo;
                    tempDerevo=perent->son;
                    vstavka(tempDerevo,sun);
                }
        }else{
                if(perent->Spiert==NULL){
                    printf("2\n");
                    perent->Spiert=sun;
                }else{
                    tree *tempDerevo ;
                    tempDerevo=perent->Spiert;
                    vstavka(tempDerevo,sun);
                }
        }
}





int NLR(struct tree *perent){

    printf("           %f        \n",perent->inform);

    if(perent->son!=NULL){
        NLR(perent->son);
    }
    if (perent->Spiert!=NULL){
        NLR(perent->Spiert);
    }
}


/*

int delete_el(struct tree *perent,int n){
    if(n<1||n>2||perent==NULL)return -1;
    tree* temp;
    tree* temp2;
    if(n==1){
        temp=((tree*)perent->son);
        if(perent->son!=NULL){
            if(((tree*)perent->son)->son!=NULL){
                    temp2=((tree*)perent->son)->son;

                    while(temp2->Spiert!=NULL){
                        temp2=temp2->Spiert;
                    }
                    perent->son=temp2;
                    temp2->son=NULL;
                    temp2->Spiert=NULL;

                    temp2->son=temp->son;
                    temp2->Spiert=temp->Spiert;
                    temp2->inform=temp->inform;

            }else if(((tree*)perent->son)->Spiert!=NULL){
                    perent->son=((tree*)perent->son)->Spiert;
            }
            free(temp);
        }else return -2;
    }else if(n==2){
        temp=((tree*)perent->Spiert);
        if(perent->Spiert!=NULL){
            if(((tree*)perent->Spiert)->son!=NULL){
                    temp2=((tree*)perent->Spiert)->son;
                    while(temp2->Spiert!=NULL){
                        temp2=temp2->Spiert;
                    }
                    perent->Spiert=temp2;
                    temp2->son=temp->son;
                    temp2->Spiert=temp->Spiert;
                    temp2->inform=temp->inform;

            }else if(((tree*)perent->Spiert)->Spiert!=NULL){
                    perent->Spiert=((tree*)perent->Spiert)->Spiert;
            }
            free(temp);
        }else return -2;
    }

    return 1;
}

*/




int delete_ALL(struct tree *perent){
    if(perent->son!=NULL){
        delete_ALL(perent->son);
    }
    if(perent->Spiert!=NULL){
        delete_ALL(perent->Spiert);
    }
    perent->son=NULL;
    perent->Spiert=NULL;
    free(perent);
}
