 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"



int main() {
    FILE* file = fopen("in.txt","r");
    if (file == NULL)
    {
        printf("File is empty!");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* str = malloc(size);
    fgets(str,size,file);
    Selectionsort(str,size);
     free(str);
    fgets(str,size,file);
     Insertionsort(str,size);
     free(str);
    fgets(str,size,file);
     Bubblesort(str,size);
    printf("%s\n", str);
    FILE* out = fopen("out.txt","w");
    fprintf(out, "%s\n", str);//fwrite(str,sizeof(char),size,out);
    free(str);
    fclose(file);
    fclose(out);
    return 0;
}
