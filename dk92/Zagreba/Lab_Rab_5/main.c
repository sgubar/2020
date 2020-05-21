#include <stdio.h>
#include <stdlib.h>
#include "Derevo.h"


int main()
{
    srand(time(NULL));
    derevo *big_father = (struct derevo*) malloc(sizeof(derevo));
    big_father->inform=rand();
    big_father->nomer=NULL;
    big_father->son1=NULL;
    big_father->son2=NULL;
    derevo* temp = (struct derevo*) malloc(sizeof(derevo));


    for(int i=0;i<25;i++){
        temp = sosdat(i);

        printf("    %f\n",temp->inform);
        vstavka(big_father, temp);
    }

    obhod(big_father, 0);



    printf("Hello world \n");


    free(temp);
    free(big_father);
    return 0;
}
