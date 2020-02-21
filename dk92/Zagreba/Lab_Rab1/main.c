#include <stdio.h>
#include <stdlib.h>
#include "bib.h"


int main()
{
    float A=0;
    float B=0;
    float C=0;

    float D;

    float DA;
    float DB;
    float DC;
    float DDB;

    printf("Moi bariant 5\n\n\n");
 /* //  ввод числа А
    printf("Bbedite chilo A\n");
    //float A;
    scanf("%f",&A);
    printf("Bi bbeli %f \n\n",A);
*/


        //тест

  //  ввод числа А
    printf("Bbedite chilo A\n");

 // printf("%d \n", scanf("%f",&A));




  if(scanf("%f",&A)==0){
        printf("Bi bbeli ne chislo \n");
        return -2;
  }



 //scanf("%f",&A);

    printf("Bi bbeli %f \n\n",A);




    //тест





  //  ввод числа В
    printf("Bbedite chilo B\n");
    //float B;
    if(scanf("%f",&B)==0){
        printf("Bi bbeli ne chislo \n");
        return -2;
       }

    printf("Bi bbeli %f \n\n",B);


  //  ввод числа С
    printf("Bbedite chilo C\n");
    //float C;
    if(scanf("%f",&C)==0){
        printf("Bi bbeli ne chislo \n");
        return -2;
    }
    printf("Bi bb8eli %f \n\n",C);

if(B<0)
        {

            printf("ERROR \n\n");
            return -1;}



    D=A;
    DA=stp(D);

    D=B;
    DB=stp(D);

    DC=stp5(C);

    DDB=integral(B);

    float Q;
    float Q1;
    float Q2;
    float Q3;

    Q1=(DA+DB);
    Q2=(B+DC);
    Q3=Q1/Q2;
    Q=Q3+DDB;


 printf("Otbet %f \n\n\n",Q);





    return 0;
}
