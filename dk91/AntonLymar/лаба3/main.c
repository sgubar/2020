#include <stdio.h>
#include <stdlib.h>
#include "lac.h"
#include <time.h>
int main()
{
    FILE* file = fopen("C:\\prog\\lab3\\lac\\lc.txt","r");
    if (file == NULL)
    {
        printf("Error!");
        return 0;
    }
    fseek(file, -1, SEEK_END);
    int n = ftell(file);
    printf("n = %d\n", n);
    fseek(file, 0, SEEK_SET);
    char* mass = malloc(n);
    fgets(mass, n, file);

  int f =  proverka(mass, n);
  if(f==0)
    return 0;

clock_t start, stop;
 start = clock ();
   Shells( n,  mass);
 stop = clock();
 vuvod( mass,  n);
   printf("\nTime of sorting Shells %    .5lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);


    printf("\nKey:");
 char key;
 scanf("%c", &key);
 start = clock ();
 f = poisk(mass, n, key);
 stop = clock();
 printf("\nTime of poisk %.5lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);
 if(f == -1)
 {
     printf("No elements %c",key);
 }
 else
 {
     printf("mass[%d] = %c", f, key);
 }

}
