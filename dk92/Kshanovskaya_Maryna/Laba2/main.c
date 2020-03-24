#include <stdio.h>
#include "one.h"
#include <time.h>

int main () {
       int i;
     float m = 0 ;
    FILE *myfile;
    myfile = fopen ("/Users/marinakshanovskaa/Desktop/New/laba 2/this.txt", "r");
// размер и указатель
        fseek(myfile, 0, SEEK_END); //конец файла
        m = ftell(myfile);
    fseek(myfile,0,SEEK_SET); //начало файла
    int n = m;
       char a[n];
       
       for(i = 0 ; i < n; i++) {
           scanf("%c", &a[i]);
       }
    // время
   float time0=0;
   float time1=0;
    time0 = time(NULL);
    
    int methodSort = 1;
    if (methodSort == 1) {
        
        insertionSort( a, n );
    }
    else if (methodSort == 2){

         selectionSort( a, n );
    }
    else if (methodSort == 3){
        
         bubbleSort( a, n );

    }
    
    
     time1 = time (NULL);
     printf("time = %f\n",time1 - time0);
      fclose (myfile);
   
}

