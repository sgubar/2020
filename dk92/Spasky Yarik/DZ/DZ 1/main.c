#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "dk_tools.h"

int main(int argc, char *argv[])
{
int N;
int matrix1[10][10];
int matrix2[10][10];
int result_matrix[10][10];

printf("Enter array size: \n");
scanf("%i", &N);

FirstMatrix(N,matrix1);
FirstMatrix(N,matrix2);
resultOfmultiplication(N,matrix1,matrix2,result_matrix);
print(N,result_matrix);


return 0;
}
