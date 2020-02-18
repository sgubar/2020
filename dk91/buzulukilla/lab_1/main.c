#include<stdio.h>
#include "lab_1_tool.h"
int main(int argc, char** argv) {
	
	int A,B,C,DEV_FIN,SUMM,RESULT;
	double devis,exponated;
	
	devis=devisible_test(A,B,C);
	
	exponated= exponentiation_test(C);
	
DEV_FIN = division_test(devis,exponated);

int D=0;
	
SUMM=SUMM_test(A,D);
	
RESULT=0;
	
	RESULT = DEV_FIN*SUMM;
	
	printf("the result is %d\n",RESULT);
	
	return 0;
}
