//
//  SortFunc.h
//  Laboratory work 2
//
//  Created by Nazar Diadiun on 10.03.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#ifndef SortFunc_h
#define SortFunc_h

#include <stdio.h>

long getCharacterCount();
char* fileprocess(long ArraySize);
void bubbleSort(char* matrix, long N);
void selectionSort(char* matrix, long N);
void insertionSort(char* matrix, long N);
void fileWrite(char* matrix);

#endif /* SortFunc_h */
