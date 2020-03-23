#include <stdio.h>
#include "Sort.h"

void clearoutput();
int vvod();

int main() {

    FILE *in;
    in = fopen("input.txt", "r");
    if (in == NULL){
        printf("oshibka\n");
        return 1;
    }

    clearoutput();

    int size = 1; //1-10000
    char sc [10000];
    char sor [10000];

    size = vvod();


    for(int i = 0; i < size; i++){
        fscanf(in, "%c", &sc[i]);
    }


    bubble(sc, sor, size);

    select(sc, sor, size);

    insert(sc, sor, size);

    fclose(in);
    return 0;
}

void clearoutput(){
    FILE *out;
    out = fopen("output.txt", "w");
    if (out == NULL){
        printf("oshibka\n");
    }
    fclose(out);
}

int vvod(){
    char buf[32];
    int pass = 0;
    int s;
    printf("Enter quantity of char for sort 1-10000\n");

    do{
        fgets(buf, 31, stdin);
        if(sscanf(buf, "%d", &s) != 1){
            printf("try again \n");
            pass = 0;
        }
        else{
            if( (s >= 2) || (s <= 10000)){
                pass = 1;
                printf("OK ");
                printf("%d \n",s);
            }
        }
    }while(pass != 1);
    return s;
}