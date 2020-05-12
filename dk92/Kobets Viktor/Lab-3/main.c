#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Gen.h"
#include "Sort.h"
#include "Bsearch.h"

int main()
{
    int size;
    printf("Enter the size of the line:\n");
    scanf("%u", &size);
    FILE *fp;
    genFile("name.txt", size);
    struct timespec algtime;
    while(1){
        printf("\n");
        char *mass = malloc((size + 1) * sizeof(char));
        fp = fopen("name.txt", "r");
        for(;fp == NULL;)
        {
            fp = fopen("name.txt", "r");
            printf("F\n");
        }
        memset(mass, 0, size+1);
        fscanf(fp, "%[^\n]", mass);         
        int n;
        int t;
        printf("Sort Quicksort(1), regen line(2), exit program(99)\n");
        scanf("%i", &n);
        printf("\n");

        if(n == 1){
        do{
        printf("Vivesti sortirovaniy masiv? 1(yes), 2(no)\n");
        scanf("%i", &t);
        printf("\n");
        if(t!=1 && t!=2)
        {
            printf("try again! \n");    
        }
        }
        while(t!=1 && t!=2);
        }

        switch(n)
        {
            case 1: printf("\nProgram execution time %lu nanoseconds.\n", quicksort(mass, 0, size, t)); 
            break;
            default: printf("try again! \n");
            break;
            case 2: printf("Enter the size of the line:\n");
                    scanf("%u", &size);
                    genFile("name.txt", size);
                    printf("Sort Quicksort(1), regen line(2), exit program(99)\n");
			        scanf("%i", &n);
			        printf("\n");

			        if(n == 1){
			        do{
			        printf("Vivesti sortirovaniy masiv? 1(yes), 2(no)\n");
			        scanf("%i", &t);
			        printf("\n");
			        if(t!=1 && t!=2)
			        {
			            printf("try again! \n");    
			        }
			        }
			        while(t!=1 && t!=2);
			        }
            break;
            case 99:fclose(fp);
            return 0;
        }
        
        printf("Enter search value: ");
        fflush(stdin);
        char v;
        scanf("%c", &v);
        printf("\nSearch value: %i", binsearch(mass, v, 0, size));

        free(mass);
    }
    fclose(fp);

    return 0;
}