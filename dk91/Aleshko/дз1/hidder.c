#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hidder.h"
int Umnozenie(int m[3][5], int nRow, int nCol, int F)
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
