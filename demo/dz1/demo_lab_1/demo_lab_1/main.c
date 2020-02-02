//
//  main.c
//  demo_lab_1
//
//  Created by Slava Gubar on 3/11/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "dk_math.h"

double q(int a, int b);

int main(int argc, const char * argv[]) {
	// insert code here...
	printf("The result: %f\n", q(2, 2));
	
	return 0;
}

double q(int a, int b)
{
	double pow = power(a, b);
	double base = power(1+mod(b), a);
	double summ = sum(base, b);
	
	return (pow * summ);
}
