#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dk_MATH.h"


int main()
{
	for (;;)
	{	
    fflush(stdin);    
	int pass = 0;
	int D, C;
	char F[1000];
	char p[32];

    printf("(functionD) * (functionF-C)");
	printf("Enter Variable:\n");
    printf("D = ");
    do{
        fgets(p, 31, stdin);
        if(sscanf(p, "%d", &D) != 1){
            printf("try again \n");
            pass = 0;
        }
        else{
            pass = 1;
        }
        fflush(stdin);
    }while(pass != 1);
	
    
	
    printf("Enter F16 ");
	scanf("%s", &F);
	fflush(stdin);

    printf("C = ");
    do{
        fgets(p, 31, stdin);
        if(sscanf(p, "%d", &C) != 1){
            printf("try again \n");
            pass = 0;
        }
        else{
            pass = 1;
        }
        fflush(stdin);
    }while(pass != 1);
	float result = (sum(D)*(sixth(F)-C));
	
	printf("Result = %f", result);
	
	system("pause");
	}
}