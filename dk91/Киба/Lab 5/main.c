#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"


int main()
{
    srand(time(NULL));
    tree *perent = (struct tree*) malloc(sizeof(tree));
    perent->inform=rand()%15;
    perent->son=NULL;
    perent->Spiert=NULL;
    tree* temp = (struct tree*) malloc(sizeof(tree));
    for(int i=0;i<15;i++){
        temp = creat();
        printf("    %f\n",temp->inform);
        vstavka(perent, temp);
    }
    NLR(perent);
    /*int t;
    t= delete_el(perent->son,perent->Spiert);
    printf("Hello world         %i\n",t);*/

    delete_ALL(perent);
    free(temp);
    free(perent);
    return 0;
}
