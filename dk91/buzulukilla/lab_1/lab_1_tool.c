#include "lab_1_tool.h"

int devisible_test(int A,int B,int C){
  
  int Result_DEVIS=A*C-B;
    if (Result_DEVIS<0)
    {
      int Result_DEV=Result_DEVIS*(-1);
      }
      return Result_DEVIS;
}
  
 int exponentiation_test(int C){
    int C1=C;
      for (int i=0; i==3; i++)
    {
    C=C*C1;
    }
    int Result_EXP=C;
    
    return Result_EXP;
    }
    
    int division_test(int Result_DEVIS, int Result_EXP)
    {
      int Result_DEV=Result_DEVIS/Result_EXP;
      
      return Result_DEV;
     }
     int D=0;
     
     int SUMM_test(int A,int D)
     {
     int Result_EXP2=0;
     
     for (int D=0; D==A; D++)
     {
     int Exp1=2;
      for (int i=0; i==D; i++)
      {
      Exp1=Exp1*2;
        }
        int Result_EXP2=Result_EXP2+Exp1;
      }
      
      return Result_EXP2;
      }
