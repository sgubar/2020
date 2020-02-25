#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");



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

    int c1=c-1;
    int ii=0;
    int temp=0;
    int test=0;

    FILE *file;
    file = fopen("Rezult.txt", "w");
    while(1>0){
        for(int i=0; i<c1; i++){
            ii=i+1;
                if(final_z[i]>final_z[ii]){
                    printf("%c > %c\n",final_z[i],final_z[ii]);
                    temp=final_z[ii];
                    final_z[ii]=final_z[i];
                    final_z[i]=temp;
                    test=1;
                    printf("%c < %c    [] \n",final_z[i],final_z[ii]);
                    }
            printf("%c < %c    \n",final_z[i],final_z[ii]);
        }
        printf("\n\n\n\n");



        if(test==0){
            for(int i=0; i<c1; i++){
                ii=i+1;
            printf("%c < %c    \n",final_z[i],final_z[ii]);
            fprintf(file,"%c  ",final_z[i]);
        }




            break;
        }
        test=0;
    }





    fclose(file);
    fclose(myfile);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    return 0;
}
