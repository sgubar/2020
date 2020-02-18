#include<stdio.h>
#include "lab_1_tool.h"
int main(int argc, char** argv) {
	
	int A,B,C;
	double devis,exponated;
	float DEV_FIN,SUMM,RESULT;
	A=10;
	B=10;
	C=2;
												printf("the result is %f %f %f\n",DEV_FIN,SUMM,RESULT);
	devis=devisible_test(A,B,C);
	
	exponated= exponentiation_test(C);
	
DEV_FIN = division_test(devis,exponated);
												printf("the result is %f %f %f\n",DEV_FIN,SUMM,RESULT);
int D=0;
	
SUMM=SUMM_test(A,D);
	
RESULT=0;
	
	RESULT = DEV_FIN*SUMM;
	
	printf("the result is %f %f %f\n",DEV_FIN,SUMM,RESULT);
	
	return 0;
}
