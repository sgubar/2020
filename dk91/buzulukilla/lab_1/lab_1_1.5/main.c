
#include<stdio.h>
#include "lab_1_tool.h"
int main(int argc, char** argv) {
	
	int A,B,C,D;
	double devis,exponated;
	float SUMM,RESULT;
	
		
printf("enter next variable's\n");

	printf("\nA=");
	scanf("%i",&A);
	
	
	
		printf("\nB=");
		scanf("%i",&B);
			
			
			
			printf("\nC=");
			scanf("%i",&C);	
			
			
											
	devis=devisible_test(A,B,C);
	exponated= exponentiation_test(C);
										
	float DEV_FIN = division_test(devis,exponated);

	
	SUMM=SUMM_test(A);

	RESULT=0;
	
	RESULT = DEV_FIN*SUMM;
	
	printf("the result is %.3f\n",RESULT);
	
	return 0;
}
