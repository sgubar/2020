#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SSS.h"
int main()
{
    FILE* file = fopen("D:\\in.txt","r");
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

  int f =  revice(mass, n);
  if(f==0) return 0;

clock_t start, stop;
 start = clock ();
   ShellSort( n,  mass);
 stop = clock();
 fff( mass,  n);
   printf("\nTime of sorting ShellSort %.5lf seconds\n\n", (double)(stop - start) / CLOCKS_PER_SEC);


    printf("\nKey:");
 char key;
 scanf("%c", &key);
 f = poisk(mass, n, key);
 if(f == -1)
 {
     printf("No elements %c",key);
 }
 else
 {
     printf("mass[%d] = %c", f, key);
 }

}
