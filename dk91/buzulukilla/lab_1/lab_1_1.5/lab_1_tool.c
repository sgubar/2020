#include "lab_1_tool.h"

int devisible_test(int A,int B,int C){
  
  int Result_DEVIS=A*C-B;
   
    if (Result_DEVIS<0)
    {
      Result_DEVIS=Result_DEVIS*(-1);
      }
      return Result_DEVIS;
}

  
 int exponentiation_test(int C){
    int C1=C;
      for (int i=0; i!=3; i++)
    {
    C=C*C1;
    }    
    return C ;
    }
    
    float division_test(int Result_DEVIS, int Result_EXP)
    { 
      return (float)Result_DEVIS/(float)Result_EXP;
     }
     
	  
	int power(int pow)
	{	int result_pow_2=0;
		for (int a=0;a!=pow;a++)
		{
			result_pow_2=2*a+result_pow_2;
		}
		return result_pow_2;
	}
	 
	 
	 int SUMM_test(int A)
     {
     int Result_EXP2=0;
     
     for(int D=0;D!=A;D++)
     {
    	Result_EXP2=power(D)+Result_EXP2;
	 }
     
      return Result_EXP2;
      }
