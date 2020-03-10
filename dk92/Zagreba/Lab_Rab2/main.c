#include <stdio.h>
#include <stdlib.h>
#include "bib.h"


int main()
{
        int metod=2;
        /*
            1-бульбашка
            2-вставки
            3-выбор
        */

    FILE *myfile;
    myfile = fopen ("hello.txt", "r");


    int b;

    int c=0;


    fseek(myfile,0,SEEK_END);
    b=ftell(myfile);

    int z=b--;

    b=b+2;
    char a[b];
    char final_z[b];



    fseek(myfile,0,SEEK_SET);

    fgets (a, b, myfile);

    for(int i=0; i<z; i=i+1){
        if(isalpha (a[i])!=0){
            final_z[c]=a[i];
            c++;
        }
    }




    if(metod==1) bublle(final_z, c);
    else if(metod==2)vctav(final_z,c);
    else if(metod==3) vibor(final_z, c);


    fclose(myfile);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    return 0;
}
