#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"
#include "2Serch.h"

int vvodInt();
char vvodChar();
void genCharInFile(int length);
void ReadFileToArray(char toArray[], int size);
void printInFile(char printsArray[], int sizeArray);

int main() {

    int size;
    size = vvodInt();

    genCharInFile(size);

    char *quick = malloc(size * sizeof(char));

    ReadFileToArray(quick, size);

    quickSort2(quick, 0, size - 1);

    printInFile(quick, size);

    char SerchElement = vvodChar();

    printf("%d", binarSerch(quick, SerchElement, size));

    free(quick);

    return 0;
}

int vvodInt(){
    char buf[32];
    int pass = 0;
    int s;
    printf("Enter quantity of char for sort 2-2000000000\n");

    do{
        fgets(buf, 31, stdin);
        if(sscanf(buf, "%d", &s) != 1){
            printf("try again \n");
            pass = 0;
        }
        else{
            if( (s > 2) && (s < 2000000000)){
                pass = 1;
                printf("OK %d \n",s);
            } else{
                printf("try again \n");
            }
        }
    }while(pass != 1);
    return s;
}

char vvodChar(){
    char buf[32];
    int pass = 0;
    int c;
    printf("Enter letter to search position\n");

    do{
        fgets(buf, 31, stdin);
        if(sscanf(buf, "%c", &c) != 1){
            printf("try again \n");
            pass = 0;
        }
        else{
            if( ( (c >= 65) || (c <= 90) ) || ( (c >= 97) || (c <= 122) ) ){
                pass = 1;
                printf("OK %c \n",c);
            } else{
                printf("try again \n");
            }
        }
    }while(pass != 1);
    return c;
}



void genCharInFile(int length)
{
    FILE *in; // clean
    in = fopen("input.txt", "w");
    if (in == NULL){
        printf("oshibka\n");
    }
    char a;
    for(int i=0; i < length; i++)
    {
        if(rand()%2){
            a = (rand()%26)+65;
        }
        else{
            a = (rand()%26)+97;
        }
        fprintf(in, "%c", a);
    }
    fflush(in);
    fclose(in);
}

void ReadFileToArray(char toArray[], int sizeArray){

    FILE *in; // clean
    in = fopen("input.txt", "r");
    if (in == NULL){
        printf("oshibka\n");
    }

    for(int i = 0; i < sizeArray; i++){
        fscanf(in, "%c", &toArray[i]);
    }

    fclose(in);
}

void printInFile(char printsArray[], int sizeArray){

    FILE *out;
    out = fopen("output.txt", "w");
    if (out == NULL){
        printf("oshibka\n");
    }

    for(int a = 0; a < sizeArray; a++)
    {
        if(a % 1000 == 0){
            fprintf(out, "\n %d ", a);
        }
        fprintf(out, "%c", printsArray[a]);
    }

    fflush(out);
    fclose(out);
}