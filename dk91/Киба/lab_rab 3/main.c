#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jiktl.h"

int main(){

    int size_os = 0;
    int o=0;
    int i=0;
    int n=0;
    int j=0;
    float t=0;
    float t1=0;
    int loc=0;
    FILE *file = fopen ("1.txt", "r");
    int size;
    fseek(file,0,SEEK_END);
    size = ftell(file);
    fseek(file,0,SEEK_SET);
    size_os = size++;
    char *r = (char *)malloc(sizeof(char)*size_os);
    fgets (r, size_os, file);
    for(i=0; i<size_os; i++){
        if(isalpha (r[i])==1){
            o++;
        }
    }
    char *ar = malloc(sizeof(char)*o);


    for(i=0; i<size_os; i++){
        if(isalpha (r[i])){
            ar[n]=r[i];
            n++;
        }
    }
    for(int i=0;i<size_os-1;i++){
        printf("%c",ar[i]);
    }
    printf("\n");

    t = time(NULL);
    quic(ar, 0,size_os-1);
    t1 = time (NULL);


    for(int i=0;i<size_os-1;i++){
        printf("%c",ar[i]);
    }
    printf("\n");


    printf("time=%i\n", t1-t);

    char scan=0;
    int stait=0;
    printf("Enter the letter\n");
    scanf("%c", &scan);
    t = time(NULL);
    loc =  scaning(scan,ar,n);
    t1 = time (NULL);
    if(loc == NULL){
        printf("Ne nashol\n");
    }
    else{
        printf("search finish\n  index = %i\n",loc);
    }
    printf("     time = %i\n",t1-t);
    printf("write to file\n");
    FILE *NEfail = fopen("Rezult.txt", "w");
    for( j=0; j<size_os; j++){
        fprintf(NEfail,"  %c \n",ar[j]);
    }
    fclose(file);
    fclose(NEfail);
    return 0;
}
