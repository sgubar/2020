
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"



int main() {
    FILE* file = fopen("in.txt","r");
    if (file == NULL)
    {
        printf("Error!");
        return 0;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);// berem adres ukazatelya v potoke faila
    fseek(file, 0, SEEK_SET);
    char* str = malloc(size);// na pamyzat
    fgets(str,size,file);// v peremenyu
    sort(str,size);

    sort1(str,size);

    sort2(str,size);

    sort2(str,size);
    printf("%s\n", str);
    FILE* out = fopen("out.txt","w");
    fwrite(str,sizeof(char),size,out);
    free(str);
    fclose(file);
    fclose(out);
    return 0;
}

