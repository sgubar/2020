#include <stdio.h>
#include "list.h"
#include "slist.h"

void doTestSLList();
void doPrintSLList(const IntList *aList);


int main() {
    for(;;){
    IntList *theList = SLCreateList();
    float am = 0;
    float sum = 0;
    int size;

    printf("Enter size of list: \n");
    scanf("%d", &size);

    printf("list: ");
    for(int i=size; 0<=i; i--){
        SLAddNode(theList, SLCreateNodeWithIntValue(i));
        sum = sum + i;
    }
    am = sum/size;

    doPrintSLList(theList);

    printf("\n");
    printf("Arithmetical mean: %f\n", am);
    int pass = 1;
    for (int i = 0; i < SLCountList(theList); i++)
    {
        IntNode *theNode = SLNodeAtIndex(theList, i);
            
        if(pass == 1){
            if(theNode->size < am){
                theNode = SLRemovedNodeAtIndex(theList, i);
                pass = 0;
            }
        }
    }
    printf("Result list: ");
    doPrintSLList(theList); 
    printf("\n");
    SLFreeList(theList);
    }
}

void doPrintSLList(const IntList *aList)
{
    int pass = 1;
    for (int i = 0; i < SLCountList(aList); i++)
    {
        IntNode *theNode = SLNodeAtIndex(aList, i);
        
        if (NULL != theNode)
        {
            printf("%d, ", theNode->size);
        }
    }
    printf("\n");
}
