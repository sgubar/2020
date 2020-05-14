#include "dz_1_tool.h"

int main(int argc, char** argv) {
	
	int k,x,y,a;
	
	
	printf("enter an side length\n");
		
		scanf("%i",&a);
	
	
	int matrix_1[a][a], matrix_2[a][a],matrix_rez[a][a];


	for(x=a;x!=0;x--)
	{
		for(y=a;y!=0;y--)
		{	
			matrix_2 [x][y]	 =	random(y+x);
			printf("%i ",matrix_2[x][y]);
		}	
			printf("\n");
	} 
	
	printf("__\n");
	
	for(x=a;x!=0;x--)
	{
		for(y=a;y!=0;y--)
		{	
			matrix_1[x][y]	=	random(y*x/4);
			printf("%i ",matrix_1[x][y]);
			
		}
			printf("\n");
	} 


	printf("\n");
for(x = a; x !=0; x--){
    for(y = a; y !=0; y--)
    {
        matrix_rez[x][y] = 0;
        for(k = a; k !=0; k--)
        matrix_rez[x][y] += matrix_1[x][k]*matrix_2[k][y];
        
         printf("%i ",matrix_rez[x][y]);
    }
printf("\n");
}

	return 0;
}


