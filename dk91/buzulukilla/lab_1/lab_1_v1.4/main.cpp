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
												printf("the result is %d %d %f %f\n",devis,exponated,SUMM,RESULT);
int	DEV_FIN = division_test(devis,exponated);
												printf("the result is %d %d %f %f %f\n",devis,exponated,DEV_FIN,SUMM,RESULT);

	
SUMM=SUMM_test(A,D);
	
RESULT=0;
	
	RESULT = DEV_FIN*SUMM;
	
	printf("the result is %f %f %f\n",DEV_FIN,SUMM,RESULT);
	
	return 0;
}
