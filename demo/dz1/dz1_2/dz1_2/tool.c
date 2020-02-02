//
//  tool.c
//  dz1_2
//
//  Created by Slava Gubar on 3/5/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

#include "tool.h"

int get_numOfUpercaseSymbols(const char *inStr)
{
	int result = 0;
	
	while('\0' != *inStr)
	{
		if (*inStr >= 'A' && *inStr <= 'Z') result ++;
	
		inStr ++;
	}
	
	return result;
}

int get_numOfLowercaseSymbols(const char *inStr)
{
	int result = 0;
	
	if (NULL == inStr)
	{
		return ERROR;
	}
	
	for (; '\0' != *inStr; inStr ++)
	{
		if (*inStr >= 'a' && *inStr <= 'z') result ++;
	}
	
	return result;
}
