
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "diffsort.h"

int main()
{
int size = 0;
float timeStart, timeStop, ttimeStart, ttimeStop;

    printf("Enter size of array:");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("Print a NUMBER! Size: ");
        scanf("%d", &size);
    }

    //ранд запись и время Шелл
char mass[size];
randomizer(mass, size);
    timeStart = clock()/(float)CLOCKS_PER_SEC;
shellSort (mass, size);
    timeStop = clock()/(float)CLOCKS_PER_SEC;
    printf ("Time of Shell sorting: %.13lf\n", (double)(timeStop - timeStart)/CLOCKS_PER_SEC);

//сброс буфера
char key;
fflush(stdin);
    printf("\n\n Find this: ");
    scanf("%c", &key);
    
// время лайнсерч.
int position;
    ttimeStart = clock()/(float)CLOCKS_PER_SEC;
    position = lineSearch(mass, size, key);
    ttimeStop = clock()/(float)CLOCKS_PER_SEC;
    printf ("time of line search: %.13lf\n", (double)(ttimeStop - ttimeStart)/CLOCKS_PER_SEC);
    
        if(position != -1)
        {
            printf("Index of searched element is: %i\n", position);
            
        }
        else
        {
            printf("There is no element like that!\n");
            
        }
        return 0;
}
