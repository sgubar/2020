#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"

void doPrintSLList(const CharList *aList);

int main(int argc, const char * argv[])
{

    CharList *theList = SLCreateList();

    CharNode *theNode = SLCreateNodeWithCharValue("hello", 5);
    CharNode *theNode1 = SLCreateNodeWithCharValue("love", 4);
    CharNode *theNode2 = SLCreateNodeWithCharValue("current", 7);
    CharNode *theNode3 = SLCreateNodeWithCharValue("add", 3);
    CharNode *theNode4 = SLCreateNodeWithCharValue("telecomunication", 16);
    CharNode *theNode5 = SLCreateNodeWithCharValue("udergraduate", 12);
    CharNode *theNode6 = SLCreateNodeWithCharValue("i", 1);

    SLAddNode(theList, theNode);
    SLAddNode(theList, theNode1);
    SLAddNode(theList, theNode2);
    SLAddNode(theList, theNode3);
    SLAddNode(theList, theNode4);
    SLAddNode(theList, theNode5);
    SLAddNode(theList, theNode6);

    doPrintSLList(theList);

    quickSort(theList, 0, theList->count-1);
    printf("\nList was sorted\n\n");
    doPrintSLList(theList);

    SLFreeList(theList);

    printf("\nList was deleted!\n");

	return 0;
}

void doPrintSLList(const CharList *aList)
{
    printf("size: %d\n", SLCountList(aList));
    for (int i = 0; i < SLCountList(aList); i++)
    {
        CharNode *theNode = SLNodeAtIndex(aList, i);
        if (NULL != theNode)
        {
            printf("node[%d].size = %d word: %s", i, theNode->size, theNode->words);
            /*for(int j = 0; j < theNode->size; j++){
                printf("%s", theNode->words[j]);
            }*/
            printf("\n");
        }
    }
}

