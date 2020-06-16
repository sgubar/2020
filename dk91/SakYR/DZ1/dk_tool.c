#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool.h"
int mnoz(int m[3][3], int nRow, int nCol, int F)
{
    for(int i = 0; i < nRow; i++)
  {
      for(int j = 0; j < nCol; j++)
    {
           m[i][j] *= F;
           printf("%d\t", m[i][j]);
        } printf("\n");
    }



}
