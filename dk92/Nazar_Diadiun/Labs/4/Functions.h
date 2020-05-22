//
//  Functions.h
//  Laboratory Work 4
//
//  Created by Nazar Diadiun on 22.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#ifndef Functions_h
#define Functions_h

#include <stdio.h>
#include <stdlib.h>

typedef int Data;
 
typedef struct Node { //объявил тип, чтоб не указывать каждый раз структуру
    Data data;
    struct Node* next;
}   Node;


void EnterData(Node** list, const Data data);
void printFromHead(const Node* list);
void printFromTail(const Node* list);

#endif /* Functions_h */
