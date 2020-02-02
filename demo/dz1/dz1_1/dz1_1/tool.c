//
//  tool.c
//  dz1_1
//
//  Created by Slava Gubar on 3/4/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

#include "tool.h"

int get_len(const char *inStr)
{
	int result = 0;

	if (NULL == inStr)
	{
		return ERROR;
	}

	for (; '\0' != *inStr; inStr ++, result ++);
	
	return result;
}

int sumab(int a, int b)
{
	return (a + b);
}
