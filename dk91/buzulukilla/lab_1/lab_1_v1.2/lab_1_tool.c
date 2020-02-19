#include "lab_1_tool.h"

int devisible_test(int A,int B,int C){
  
  int Result_DEVIS=A*C-B;
    if (Result_DEVIS<0)
    {
 ?     int Result_DEVIS=Result_DEVIS*(-1);
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
    
    int division_test(int Result_DEVIS, int Result_EXP)
    { 
 ?? always int value     return Result_DEVIS/Result_EXP;
     }
     
	 
	 
?	 int D=0;
?     int Result_EXP2=0;
     
	 
	 
	 int SUMM_test(int A,int D)
     {
     
     
     for (; D!=A; D++)
     {
     int Exp1=2;
      for (int i=0; i!=D; i++)
      {
      Exp1=Exp1*2;
        }
?        int Result_EXP2=Result_EXP2+Exp1;
      }
      
      return Result_EXP2;
      }
