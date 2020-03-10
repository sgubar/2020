


#include "bib.h"



float bublle  (char final_z[], int c)
{
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
                 //   printf("%c > %c\n",final_z[i],final_z[ii]);
                    temp=final_z[ii];
                    final_z[ii]=final_z[i];
                    final_z[i]=temp;
                    test=1;
                 //   printf("%c < %c    [] \n",final_z[i],final_z[ii]);
                    }
         //   printf("%c < %c    \n",final_z[i],final_z[ii]);
        }
       // printf("\n\n\n\n");



        if(test==0){
            for(int i=0; i<c1; i++){
                ii=i+1;
         //   printf("%c < %c    \n",final_z[i],final_z[ii]);
            fprintf(file,"  %c \n",final_z[i]);
        }




            break;
        }
        test=0;
    }


    fclose(file);
}

//-----------------------------------------------------------------------
float vibor (char final_z[], int c)
{
    FILE *file;
    file = fopen("Rezult.txt", "w");
    int c1=c-1;
    int tempMesto=0;
    char temp=0;

    while(2>1){
        for(int i=1; i<c1; i++){
            if(final_z[tempMesto]<final_z[i]){
                tempMesto=i;
            }
        }
        if(final_z[tempMesto]>final_z[c1]){
            temp=final_z[tempMesto];
            final_z[tempMesto]=final_z[c1];
            final_z[c1]=temp;
        }
        c1--;
        tempMesto=0;
        if(c1==0)break;
    }
//не_добавлять_в,схему_ не_добавлять_в,схему_ не_добавлять_в,схему_ не_добавлять_в,схему_ не_добавлять_в,схему_ не_добавлять_в,схему_

        for(int i=0; i<c; i=i+1){
            fprintf(file,"  %c \n",final_z[i]);
    }
    fclose(file);
}

//----------------------------------------------------------------------
float vctav (char final_z[], int c){


    FILE *file;
    file = fopen("Rezult.txt", "w");
    //=================================================================
    int c1=c-1;
    int m=0;
    int z=1;
   // int i = 0;
    char temp;
    int zi=z;
    while(2>1){
           // printf("%c\n",final_z[z]);
                while(2>1){
                    if(final_z[z]<final_z[m]){
                       // printf("%c menau %c  \n",final_z[z],final_z[m]);
                        temp=final_z[z];
                        final_z[z]=final_z[m];
                        final_z[m]=temp;
                        z--;

                    }
                         if(m==0)break;
                    m--;
                    if(final_z[z]>final_z[m])break;
                 }
                 z=zi++;
                 m=z-1;
                 if(z==c)break;
    }

    //=================================================================
     for(int i=0; i<c; i=i+1){


         //   printf("%c--\n",final_z[i]);
            fprintf(file,"  %c \n",final_z[i]);

    }

    fclose(file);

}














