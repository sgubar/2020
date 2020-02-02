//
//  test.c
//  dz1
//
//  Created by Slava Gubar on 2/11/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#include "test.h"

float power(int n)
{
	float s=2.0;
	if(n==0)
	{
		return s=1;
	}
	
	if(n>0)
	{
		for(i=0;i<n-1;i++)
		{
			s=s*2.0;
		}
		return s;
	}
	
	if(n<0)
	{
		for(i=0;i>n+1;i--)
		{
			s=s*2.0;
		}
		return 1.0/s;
	}
}
