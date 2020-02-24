
#include<stdio.h>
#include "lab_1_tool.h"
int main(int argc, char** argv) {
	
	int A,B,C,D;
	double devis,exponated;
	float SUMM,RESULT;
	A=3;
	B=3;
	C=2;
		
											
	devis=devisible_test(A,B,C);
	printf("result of divisible: %f", devis);
	
	exponated= exponentiation_test(C);
	printf("result of exponentiation: %f", exponated);

float DEV_FIN = division_test(devis,exponated);
printf("result of division: %f", DEV_FIN);


	
SUMM=SUMM_test(A);
printf("result of SUMM: %f for A: %d\n", SUMM, A);

RESULT=0;
	
	RESULT = DEV_FIN*SUMM;
	
	printf("the result is %.3f\n",RESULT);
	
	return 0;
}
