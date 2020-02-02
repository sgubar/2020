//
//  quickSort.h
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/27/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#ifndef quickSort_h
#define quickSort_h

#include <stdio.h>
#include "SingleLinkedList.h"

int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(IntList *aList, int aLeftIndex, int aRightIndex);

#endif /* quickSort_h */
