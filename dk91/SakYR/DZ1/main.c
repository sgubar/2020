#include <stdio.h>
#include <stdlib.h>


int main()
{
    int matrix[3][3];
    int i = 0, j = 0;
    int chislo;


    for( i = 0; i < 3; i++){
        for( j = 0; j < 3; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    i = 0;
    j = 0;
    do{
        do{
            printf("%d\t", matrix[i][j]);
            j++;
        }while(j < 3);
        printf("\n");
        j = 0;
        i++;
    }while(i < 3);
    i = 0;
    j = 0;

    printf("vvedi chislo = ");
    scanf("%d", &chislo);
    int a=3, b=3;
    mnoz(matrix, a, b, chislo);
}

int mnoz(int matrix2[3][3], int i2, int j2, int chislo2)
{
    for(int i=0; i < i2; i++)
    {
        for(int j = 0; j < j2; j++)
        {
            matrix2[i][j]*= chislo2;
            printf("%d\t", matrix2[i][j]);
        } printf("\n");
    }


}
