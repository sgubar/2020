#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
int main()
{
    int dlin = 0;
    dlin=dlina();
    dlin++;
    char *read=(char *)malloc(sizeof(char)*dlin);
    schit_iz_fila(dlin,read);
    int c=0;
    c = bikvi(dlin,read, read);
    dlin=c;
    int time0=0;
    int time1=0;
    printf("quickSort Start\n");
    time0 = time(NULL);
//quickSortquickSortquickSortquickSortquickSortquickSort

 // quickSort(read, 0, c-1,0); // вызов функции сортировки
    quickSort(read, 0, c-1);

//quickSortquickSortquickSortquickSortquickSortquickSort
    time1 = time (NULL);
    printf("quickSort STOP\n");
    printf("     time = %i\n",time1-time0);
    char poiski=0;
    int mesto=0;
    printf("Vvedi bukvu\n");
    scanf("%c", &poiski);
    printf("poisk\n");
    time0 = time(NULL);
    //========================================================
    mesto =  poisk(poiski,read, c);

    //========================================================
    time1 = time (NULL);
    if(mesto==NULL){
        printf("Ne nashol\n");
    }else{
        printf("poisk STOP  index = %i\n",mesto);
    }
    printf("     time = %i\n",time1-time0);


    zapis(c,read);
    free(read);
    return 0;
}
