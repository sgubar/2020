#include <stdio.h>
#include "one.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main () {
      // int i;
     float m = 0 ;
    FILE *myfile;
    myfile = fopen ("/Users/marinakshanovskaa/Desktop/New/laba 2/test2.txt", "r");
// размер и указатель
        fseek(myfile, 0, SEEK_END); //конец файла
        m = ftell(myfile);
    printf("SIZE: %f\n", m);

    fseek(myfile,0,SEEK_SET); //начало файла
    int n = m;
       char a[n];
       
    fgets(a, n, myfile);
    printf(" %s\n", a);

      // for(i = 0 ; i < n; i++) {
         //  scanf("%c", &a[i]);
     //  }
    // время
/*float time0=0;
   float time1=0;
    time0 = time(NULL);*/
    
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
    /*
    time_t t0 = time(0);
    insertionSort( a,  n);
    time_t t1 = time(0);
  float  time = difftime(t1, t0);
   // printf("time = %lf\n",difftime(t1,t0));
    printf("time = %lf\n", time);
    */
    
    
     /*time1 = time (NULL);
     printf("time = %f\n",time1 - time0);
      fclose (myfile);
   */

clock_t time;
char ArrayOG[50000];
char Array[50000];
int Size = 100000;
    
FILE *file;
file = fopen("Result.txt", "w");
    
    
fscanf(file, "%s", ArrayOG);

    strcpy(Array, ArrayOG);
    time = clock();
    bubbleSort(Array, Size);
    time = clock() - time;
    printf("\n Time of Bubble Sort is  %f \n", (double)time/CLOCKS_PER_SEC);
    fprintf(file, "\n\n");
    
    
    strcpy(Array, ArrayOG);
    time = clock();
    insertionSort(Array, Size);
    time = clock() - time;
    printf(" Time of Insertion Sort is  %f \n", (double)time/CLOCKS_PER_SEC);
    fprintf(file, "\n\n");
    
    
    strcpy(Array, ArrayOG);
    time = clock();
    selectionSort(Array, Size);
    time = clock() - time;
    printf(" Time of Selection Sort is  %f\n ", (double)time/CLOCKS_PER_SEC);
     fprintf(file, "\n\n");
    
fclose(file);

return 0;
}
