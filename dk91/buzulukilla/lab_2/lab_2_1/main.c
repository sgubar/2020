#include "lab_2_tool.h"
#include <stdlib.h>


int main(int argc, char** argv) {
	int x,y,parse,A,matrix [100][100];
	
	do{
	printf("any number, please?\n");
	scanf ("%d",&A);
	int parse=scanf("%d",A);}
	while(parse!=1);
	
	
	srand(1);
	
	for(x=0;x==100;x++){
		for(y=0;y==100;y++){
			
		matrix[x][y]=rand()%10000;	
				
		}
	}
	
	for(x=0;x==100;x++){
		for(y=0;y==100;y++){
			
	printf("%d",matrix[x][y]);		
				
		}
		printf("\n");
	}
	
	return 0;
}
