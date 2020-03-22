#include <stdio.h>
#include <stdlib.h>


   #include "dk_tool.h"

int dk_factorial(int num_A){
    if(num_A < 1)
    	return -1;
    	else if (num_A<0||num_A>10)
    	exit(-1);
	else
	{
		int result = 1;
		int current_num = 1;
		while(current_num <= num_A)
		{
			result *= current_num;
			current_num++;
		}
		return result;
	}
}
    double dk_mnogennya( float num_A )
    {
    	double result_1;
    	result_1 = num_A * 2;

    	return result_1;
}

double dk_suma(double result_1, float num_B){
	 double result_2;
	      result_2 = result_1 + num_B;
	      if ( num_B < -9999 || num_B > 9999)
           exit(-1);
	      else if (result_2 == 0)
            exit(-1);
        else if(result_2 < 0)
	 	return result_2 *= -1;
	 else
	 	return result_2;

	 }

      double dk_dilennya(double result_2, double result){
  	double result_3;
  	result_3 = result_2 / result;

  	return result_3;

 }

