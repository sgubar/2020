
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
	
	exponated= exponentiation_test(C);
											
float DEV_FIN = division_test(devis,exponated);
												

	
SUMM=SUMM_test(A);
	
RESULT=0;
	
	RESULT = DEV_FIN*SUMM;
	
	printf("the result is %.3f\n",RESULT);
	
	return 0;
}
