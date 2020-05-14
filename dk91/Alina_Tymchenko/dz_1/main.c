#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
  int i = 0;
  int j = 0;
  int lenght1 = 5;
  int lenght2 = 5;
  int userValue = 0;
  int A[5][5];
  int B[5][5];
  int C[5][5];
  do {
     do {
         printf("vvedit' znachenya dlya 1 matrytsy: %d% d\n", i, j);
         scanf("%d", &userValue);
         A[i][j] = userValue;
         j++;
     } while (j < 5);
     j = 0;
     i++;
  } while (i < 5);

   printf("\n\n Matrix1:\n\n");


    for(i=0;i<5;i++){

        for(j=0;j<5;j++){

            printf("%d  ", A[i][j]);

        }

        printf("\n");
    }

  i = 0;
  j = 0;
  do {
     do {
         printf("vvedit' znachenya dlya 2 matrytsy: %d% d\n", i, j);
         scanf("%d", &userValue);
         B[i][j] = userValue;
         j++;
     } while (j < 5);
     j = 0;
     i++;
  } while (i < 5);

   printf("\n\n Matrix2:\n\n");


    for(i=0;i<5;i++){

        for(j=0;j<5;j++){

            printf("%d  ", B[i][j]);

        }

        printf("\n");
    }

  i = 0;
  j = 0;

  sum(A, B, C);

    printf("\n\n Result:\n\n");


    for(i=0;i<5;i++){

        for(j=0;j<5;j++){

            printf("%d  ", C[i][j]);

        }

        printf("\n");
    }

    free(A);
    free(B);

    return 0;
}
