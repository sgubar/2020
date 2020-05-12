#include <stdio.h>
#include "lists.h"
#include "singlList.h"
#include "sort.h"

void doTestSLList();
void doPrintSLList(const IntList *aList);


int main() {

    IntList *theList = SLCreateList();
    SLAddNode(theList, SLCreateNodeWithIntValue("Mans",4));
    SLAddNode(theList, SLCreateNodeWithIntValue("Not",3));
    SLAddNode(theList, SLCreateNodeWithIntValue("hot",3));
    SLAddNode(theList, SLCreateNodeWithIntValue("I",1));
    SLAddNode(theList, SLCreateNodeWithIntValue("want",4));
    SLAddNode(theList, SLCreateNodeWithIntValue("to",2));
    SLAddNode(theList, SLCreateNodeWithIntValue("have",4));
    SLAddNode(theList, SLCreateNodeWithIntValue("a",1));
    SLAddNode(theList, SLCreateNodeWithIntValue("rest",4));


    doPrintSLList(theList);

    printf("\n");

    quickSort(theList, 0, theList->count - 1);

    doPrintSLList(theList);

    SLFreeList(theList);

    //doTestSLList();

    return 0;
}

void doPrintSLList(const IntList *aList)
{
    for (int i = 0; i < SLCountList(aList); i++)
    {
        IntNode *theNode = SLNodeAtIndex(aList, i);
        if (NULL != theNode)
        {
            printf("node[%d]. size = %d word - ", i, theNode->size);
            for(int f = 0; f < theNode->size; f++){
                printf("%c", theNode->words[f]);
            }
            printf("\n");
        }
    }
}