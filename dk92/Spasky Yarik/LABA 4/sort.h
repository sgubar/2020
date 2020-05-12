#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include "SingleLinked_List.h"

int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void Sort(IntList *aList, int aLeftIndex, int aRightIndex);


#endif
