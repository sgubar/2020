#include <stdio.h>
#include <stdlib.h>


#include "dk_tool.h"




int main()
{
   float num_A,num_B;

    printf("Q=A!/|2*A+B|\n vvedute 'A' od 0 do 10 :");



    scanf("%f",&num_A);
    if(num_A<0||num_A>10)
    {
        printf("Invalid value.");
        return -1;
    }
    printf("vvedute 'B' od -9999 do +9999 :");

    scanf("%f",&num_B);
    if(num_B<-9999||num_B>9999)
    {
        printf("Invalid value.");
        return -1;
    }
    printf("A=%f, B=%f\n", num_A,num_B);

    float first_step = dk_factorial(num_A);
    float second_step = dk_mnogennya(num_A);
    float third_step = dk_suma(second_step, num_B);
    float forth_step = dk_dilennya(first_step, third_step);



    printf("Q=%f\n",dk_dilennya(dk_factorial(num_A), dk_suma(dk_mnogennya(num_A), num_B)));
    return 0;
}


