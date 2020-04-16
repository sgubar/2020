#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dk_MATH.h"

void input(int *P)
{
    char p[32];
    int pass = 0;
 do{
        fgets(p, 31, stdin);
        if(sscanf(p, "%d", P) != 1){
            printf("try again \n");
            pass = 0;
        }
        else{
            pass = 1;
        }
        fflush(stdin);
    }while(pass != 1);
}

int main()
{
	for (;;)
	{	
    fflush(stdin);    
	
	int D, C;
	char F[1000];
	
    printf("(functionD) * (functionF-C)\n");
	printf("Enter Variable:\n");
    printf("D = ");
    
    input(&D);
	
    printf("Enter F16 ");
	scanf("%s", &F);
	fflush(stdin);

    printf("C = ");
    
    input(&C);
	
    float result = (sum(D)*(sixth(F)-C));
	
	printf("Result = %f", result);
	
	system("pause");
	}
}