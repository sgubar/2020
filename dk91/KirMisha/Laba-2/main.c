
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SORTIROVCA.h"



int main() {
    FILE* Ret = fopen("in.txt","r");
    fseek(Ret, 0, SEEK_END);
    int longe = ftell(Ret);
    fseek(Ret, 0, SEEK_SET);
    char* erte = malloc(longe);
    fgets(erte,longe,Ret);
    sort(erte,longe);


    return 0;
}

