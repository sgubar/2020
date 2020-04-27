#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fdd.h"
int main()
{
      FILE* file = fopen("D:\\in.txt","r");
    if (file == NULL)
    {
        printf("Error!");
        return 0;
    }
    fseek(file, -2, SEEK_END);
    int n = ftell(file);
    printf("n = %d\n", n);
    fseek(file, 0, SEEK_SET);
    char* a = malloc(n);
    fgets(a, n, file);
 clock_t start, stop;
 fff(a, n);
 printf("\n\n");
 start = clock ();
    Insertion__Sort(a, n);
 stop = clock();
   printf("\nTime of sorting Insertion__Sort %.10lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);
 start = clock ();
    Selection__Sort(a, n);
 stop = clock();
   printf("\nTime of sorting Selection__Sort %.10lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);
 start = clock ();
    Bubble__Sort(a, n);
 stop = clock();
   printf("\nTime of sorting Bubble__Sort %.10lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
