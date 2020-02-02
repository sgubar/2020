//
//  dk_tool.c
//  dz1
//
//  Created by Slava Gubar on 2/14/18.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include "dk_tool.h"

int test_getLength(char inString[])
{
	int theResult = 0;
	
	while (NULL != inString &&
				'\0' != *(inString + theResult))
	{
		theResult ++;
	}
	
	return theResult;
}

int test_getLowercaseAlphabetCount(char *inString)
{
	int theResult = 0;
	
	if (NULL == inString)
	{
		return 0;
	}
	
	while ('\0' != *inString)
	{
		if (*inString >= 'a' && *inString <= 'z')
		{
			theResult ++;
		}
	
		inString ++;
	}
	
	return theResult;
}
