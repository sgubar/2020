//
// Created by chelt on 11.05.2020.
//

#include "sort.h"
#include "singlList.h"

int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex + 1;

    while (1)
    {
        // search the bigest element
        while (theLeft < aRightIndex && SLNodeAtIndex(aList, ++theLeft
        )->size < aPivot);

        // search the lowest element
        while (theRight > aLeftIndex && SLNodeAtIndex(aList,--theRight)->size > aPivot);

        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements

            SLSwapNodesByIndex(aList, theLeft, theRight);
        }
    }

    return theLeft; // return break position
}


void quickSort(IntList *aList, int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0)
    {
        return; // the array size equals to 1 - the array is fully sorted
    }

    int thePivot = SLNodeAtIndex(aList, aRightIndex)->size;
    int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);

    //left part sorting
    quickSort(aList, aLeftIndex, thePartitionIndex - 1);

    //right part sorting
    quickSort(aList, thePartitionIndex + 1, aRightIndex);
}
