//
// Created by chelt on 09.03.2020.
//

#include <stdio.h>
#include <time.h>
#include "Sort.h"

void bubble(char inputm[], char outputm[],  int sizem){
    clock_t theStart0 = clock();
    for (int theOut = sizem - 1; theOut > 1; theOut --)
    {
        for (int theIn = 0; theIn < theOut; theIn ++)
        {
            if (inputm[theIn] < inputm[theIn + 1])
            {
                char temp = inputm[theIn];
                inputm[theIn] = inputm[theIn + 1];
                inputm[theIn + 1] = temp;
            }
        }
    }
    clock_t theEnd0 = clock();
    printf ("Time bubble: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

    for (int i = 0; i < sizem; ++i) {
        outputm[i] = inputm[i];
    }

    FILE *out;
    out = fopen("output.txt", "a");
    if (out == NULL){
        printf("oshibka\n");
    }

        fprintf(out, "\n bubble Time : %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
        for(int i = 0; i < sizem; i++){
            fprintf(out, "%c", outputm[i]);
        }

    fflush(out);
    fclose(out);

}

void select(char inputm[], char outputm[], int sizem){
    clock_t theStart0 = clock();
    for (int theOut = 0; theOut < sizem - 1; theOut ++)
    {
        int min = theOut; //можно ли поставить мин по зансчению А 65

        for (int theIn = theOut + 1; theIn < sizem; theIn ++)
        {
            if (inputm[theIn] > inputm[min])
            {
                min = theIn;
            }
        }

        char temp = inputm[theOut];
        inputm[theOut] = inputm[min];
        inputm[min] = temp;
    }
    clock_t theEnd0 = clock();
    printf ("Time select: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);


    for (int i = 0; i < sizem; ++i) {
        outputm[i] = inputm[i];
    }

    FILE *out;
    out = fopen("output.txt", "a");
    if (out == NULL){
        printf("oshibka\n");
    }

        fprintf(out, " \n select Time : %.10lf \n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
        for(int i = 0; i < sizem; i++){
            fprintf(out, "%c", outputm[i]);
        }

    fflush(out);
    fclose(out);
}

void insert(char inputm[], char outputm[], int sizem){
    clock_t theStart0 = clock();
    for (int theOut = 1; theOut < sizem; theOut ++)
    {
        char temp = inputm[theOut];
        int theIn = theOut;

        while ( (theIn > 0) && (inputm[theIn - 1] <= temp) )
        {
            inputm[theIn] = inputm[theIn - 1];
            -- theIn;
        }

        inputm[theIn] = temp;
    }
    clock_t theEnd0 = clock();
    printf ("Time insert: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

    for (int i = 0; i < sizem; ++i) {
        outputm[i] = inputm[i];
    }

    FILE *out;
    out = fopen("output.txt", "a");
    if (out == NULL){
        printf("oshibka\n");
    }

        fprintf(out, "\n insert Time : %.10lf \n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
        for(int i = 0; i < sizem; i++){
            fprintf(out, "%c", outputm[i]);
        }

    fflush(out);
    fclose(out);
}