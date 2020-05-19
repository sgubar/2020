#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lac.h"
void Shells(int n, char mass[])
{

    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
       {

        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j = j - step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
       }
}
void vuvod(char *a, int n)
{
 printf("\n");
    for (int i=0; i<n; i++)
    {
      printf("%c", a[i]);
    }
 printf("\n");
}
int proverka(char *mass, int n)
{
    int i;
    for(i=0; i<n-2; i++)
    {
        if((mass[i]>96 & mass[i]<123) || (mass[i]>47 & mass[i]<58) )
        {
         printf("%c", mass[i]);
        }
        else
        {

            printf("\nError %c", mass[i]);
            return 0;
        }
    }
    return 1;
}
int poisk(char *m, int n, char key)
{


  for (int i = 0; i < n; i++)
  {
    if (m[i] == key)
      return i;
  }
  return -1;
}
