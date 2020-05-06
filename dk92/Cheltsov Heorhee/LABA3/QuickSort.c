//
// Created by chelt on 04.05.2020.
//

#include "QuickSort.h"


//static void swap(char anArray[], int aLeftIndex, int aRightIndex);
//static char mediana(char anArray[], int aLeftIndex, int aRightIndex);
//static char m_partitionIt(char anArray[], int aLeftIndex, int aRightIndex, char aPivot);
//static void m_manualSort(char anArray[], int aLeftIndex, int aRightIndex);


int partitionIt(char anArray[], int aLeftIndex, int aRightIndex, char aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex;

    while (1)
    {
        // search the bigest element
        while (anArray[++theLeft] < aPivot);

        // search the lowest element
        while (theRight > 0 && anArray[--theRight] > aPivot);

        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            int theTmp = anArray[theLeft];
            anArray[theLeft] = anArray[theRight];
            anArray[theRight] = theTmp;
        }
    }

    //lets to swap elements
    int theTmp = anArray[theLeft];
    anArray[theLeft] = anArray[aRightIndex];
    anArray[aRightIndex] = theTmp;

    return theLeft; // return break position
}

void quickSort(char anArray[], int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0)
    {
        return; // the array size equals to 1 - the array is fully sorted
    }

    char thePivot = anArray[aRightIndex];
    int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

    //left part sorting
    quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

    //right part sorting
    quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}

//void swap(char anArray[], int aLeftIndex, int aRightIndex)
//{
//    char theTmp = anArray[aLeftIndex];
//    anArray[aLeftIndex] = anArray[aRightIndex];
//    anArray[aRightIndex] = theTmp;
//}

//char mediana(char anArray[], int aLeftIndex, int aRightIndex)
//{
//    int theCenter = (aLeftIndex + aRightIndex) / 2;
//
//    if (anArray[aLeftIndex] > anArray[theCenter])
//    {
//        swap(anArray, aLeftIndex, theCenter);
//    }
//
//    if (anArray[aLeftIndex] > anArray[aRightIndex])
//    {
//        swap(anArray, aLeftIndex, aRightIndex);
//    }
//
//    if (anArray[theCenter] > anArray[aRightIndex])
//    {
//        swap(anArray, theCenter, aRightIndex);
//    }
//
//    swap(anArray, theCenter, aRightIndex - 1);
//
//    return anArray[aRightIndex - 1];
//}

//char m_partitionIt(char anArray[], int aLeftIndex, int aRightIndex, char aPivot)
//{
//    int theLeft = aLeftIndex;
//    int theRight = aRightIndex - 1;
//
//    while (1)
//    {
//        // search the bigest element
//        while (anArray[++theLeft] < aPivot);
//
//        // search the lowest element
//        while (anArray[--theRight] > aPivot);
//
//        if (theLeft >= theRight) // pointer are the same
//        {
//            break;
//        }
//        else
//        {
//            //lets to swap elements
//            swap(anArray, theLeft, theRight);
//        }
//    }
//
//    //lets to swap elements
//    swap(anArray, theLeft, aRightIndex - 1);
//
//    return theLeft; // return break position
//}

//void quickSort2(char anArray[], int aLeftIndex, int aRightIndex)
//{
//    int theSize = aRightIndex - aLeftIndex + 1;
//
//    if (theSize <= 3)
//    {
//        m_manualSort(anArray, aLeftIndex, aRightIndex);
//    }
//    else
//    {
//        char thePivot = mediana(anArray, aLeftIndex, aRightIndex);
//        int thePartitionIndex = m_partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
//
//        //left part sorting
//        quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
//
//        //right part sorting
//        quickSort(anArray, thePartitionIndex + 1, aRightIndex);
//    }
//}
//
//
//void m_manualSort(char anArray[], int aLeftIndex, int aRightIndex)
//{
//    int theSize = aRightIndex - aLeftIndex + 1;
//
//    if (theSize <= 1)
//    {
//        return;
//    }
//
//    if (2 == theSize)
//    {
//        if (anArray[aLeftIndex] > anArray[aRightIndex])
//        {
//            swap(anArray, aLeftIndex, aRightIndex);
//        }
//        return ;
//    }
//    else
//    {
//        // 3 elementes
//        if (anArray[aLeftIndex] > anArray[aRightIndex - 1])
//        {
//            swap(anArray, aLeftIndex, aRightIndex - 1);
//        }
//
//        if (anArray[aLeftIndex] > anArray[aRightIndex])
//        {
//            swap(anArray, aLeftIndex, aRightIndex);
//        }
//
//        if (anArray[aRightIndex - 1] > anArray[aRightIndex])
//        {
//            swap(anArray, aRightIndex - 1, aRightIndex);
//        }
//    }
//}