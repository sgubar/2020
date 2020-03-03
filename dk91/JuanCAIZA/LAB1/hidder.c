//
//  hidder.c
//  demo_lab_1
//
//  Created by Slava Gubar on 03.03.2020.
//  Copyright © 2020 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "hidder.h"

double step(int base, int exp)
{
    int a = base;
    if(exp > 0){

         for(int i = 1; i < exp; i++)
    {
        base *= a;
    }
    return base;
    }else if(exp < 0){
        for(; exp < -1; exp++)
    {
        base *= a;
    }
    return 1.0 / base;
    }else{
        return 1;
    }


}
double fac(int in)
{   int out = 1;
if (in>=0){
    for(int i = 1; i<=in; i++)
    {
      out*=i;
    }
    return out;
	}else return 0;
}


double sum(int finish, int start)
{
    int a = 0;
    for(; start <=finish; start++)
        {
            a = a + fac(start);
        }
        return a;
}
