#include "diffsort.h"
#include <stdlib.h> 

void shellSort(char *mass, int Count)
{
    int theInner = 0;
    int theOuter = 0;
    int theH = 1; // start h = 1

    //1. Calculate start value of h
    while (theH <= Count/3)
    {
        theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
    }

    //2. Sequental decrease h to 1
    while (theH > 0)
    {
        for (theOuter = theH; theOuter < Count; theOuter ++)
        {
            int theTmp = mass[theOuter];
            theInner = theOuter;

            // the first sub-array {0, 4, 8}
            while (theInner > theH-1 && mass[theInner - theH] >= theTmp)
            {
                mass[theInner] = mass[theInner - theH];
                theInner -= theH;
            }

            mass[theInner] = theTmp;
        }

        theH = (theH - 1) / 3; //decrease h
    }
}

//лінійний пошук
int lineSearch(char *array, int size, const char key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == array[i])
        {
            return i;
        }
    }
    return -1;
}



//рандомнная запись заданного массива
void randomizer (char *mass, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        switch(rand()%2)
        {
            case 0: mass[i] = rand() % 26 + 97;
            break;
            case 1: mass[i] = rand() % 10 + 48;
            break;
        }
    }
}
