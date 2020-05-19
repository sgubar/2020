#include "sort.h"
#include <stdio.h>
#include <stdlib.h>


	//help function
int partition(List *aList, int start, int end)
{
    int pivot = nodeAtIndex(aList, end)->value;

    int i = (start - 1);

    for (int j = start; j <= (end - 1); j++)
    {
        if ( (nodeAtIndex(aList, j)->value) <= (nodeAtIndex(aList, i)->value))	//<= up, >= down
        {
            i++;

            int temp_i = nodeAtIndex(aList, i)->value;
			nodeAtIndex(aList, i)->value = nodeAtIndex(aList, j)->value;
			nodeAtIndex(aList, j)->value = temp_i;
        }
    }

    swapNodes(aList, i + 1, end);

    return (i + 1);
}

//quick sort
	//sort
void quickSort(List *aList, int start, int end)
{
	if (start > end)
	{
        int temp=start;
        start=end;
        end=temp;
    }
        for (int i= start;i<end;++i){
            for (int j = i; j <end; j++)
            {
                if ( (nodeAtIndex(aList, j)->value) <= (nodeAtIndex(aList, i)->value))	//<= up, >= down
                {

                    //swapNodes(aList, i, j);

                    int temp_i = nodeAtIndex(aList, i)->value;
                    nodeAtIndex(aList, i)->value = nodeAtIndex(aList, j)->value;
                    nodeAtIndex(aList, j)->value = temp_i;
                }
            }
        }

}
