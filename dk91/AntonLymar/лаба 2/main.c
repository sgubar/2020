#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sitte.h"
int main()
{
      FILE* file = fopen("C:\\prog\\lab2\\sitte\\dayk.txt.txt","r");
    if (file == NULL)
    {
        printf("hERROR!");
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
 printf("\n\nK:");
 int k;
 scanf("%d", &k);
 switch(k)
 {
     case 1:
  start = clock ();
   Insertion__Sort(a, n);
 stop = clock();
   printf("\nTime of sorting Insertion__Sort %.10lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);
    break;
    case 2:
 start = clock ();
    Selection__Sort(a, n);
 stop = clock();
   printf("\nTime of sorting Selection__Sort %.10lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);
 break;
 case 3:
 start = clock ();
    Bubble__Sort(a, n);
 stop = clock();
   printf("\nTime of sorting Bubble__Sort %.10lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);
 break;
 }
}
