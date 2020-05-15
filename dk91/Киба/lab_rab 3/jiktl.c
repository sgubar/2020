#include "jiktl.h"
#include <stdio.h>
#include <stdlib.h>
int partitionIt(char anArray[], int aLeftIndex, int aRightIndex, char aPivot)
{
  int theLeft = aLeftIndex - 1;
  int theRight = aRightIndex;

  while (1)
  {

    while (anArray[++theLeft] > aPivot);


    while (theRight > 0 && anArray[--theRight] < aPivot);

    if (theLeft >= theRight){
      break;
    }
    else
    {

      char theTmp = anArray[theLeft];
      anArray[theLeft] = anArray[theRight];
      anArray[theRight] = theTmp;
    }
  }

  //lets to swap elements
  char theTmp = anArray[theLeft];
  anArray[theLeft] = anArray[aRightIndex];
  anArray[aRightIndex] = theTmp;

  return theLeft;
}

void quic(char anArray[], int aLeftIndex, int aRightIndex)
{
  if (aRightIndex - aLeftIndex <= 0)
  {
    return;
  }

  char thePivot = anArray[aRightIndex];
  int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

  quic(anArray, aLeftIndex, thePartitionIndex - 1);
  quic(anArray, thePartitionIndex + 1, aRightIndex);

}

int scaning(char scan,char ar[],int c){
if(isalpha (scan)==1){




    int m=0;
    for(int i=0;i<c;i++){

       if(ar[i]==scan){
            m=i;

            return m;
        }
    }
}
  printf("Not the correct item \n");
   return NULL;
}

