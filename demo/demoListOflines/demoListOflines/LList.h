//
//  LList.h
//  demoListOflines
//
//  Created by Slava Gubar on 4/22/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

#ifndef LList_h
#define LList_h

#include <stdio.h>
#include "dk_line.h"

typedef struct __LLineNode LLineNode;
struct __LLineNode
{
	Line *line;
	LLineNode *next;
	LLineNode *prev;
};

typedef struct __LList
{
	int count;
	LLineNode *head;
	LLineNode *tail;
}LList;

//init/destroy
LList *createListOfLines(void);
void destroyListOfLines(LList *aList);

//
void addLineToList(LList *aList, Line *aLine);
LLineNode *lineAtIndex(LList *aList, int anIndex);
LLineNode *middleNode(LList *aList);

#endif /* LList_h */
