#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

void sum(int A[][5], int B[][5], int C[][5]){
for(int i=0;i<5;i++)
  for(int j=0;j<5;j++)
    C[i][j] = A[i][j] + B[i][j];
}
