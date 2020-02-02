//
//  main.c
//  dz1
//
//  Created by Slava Gubar on 2/14/18.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "dk_tool.h"

int main(int argc, const char * argv[])
{
	char theString[] = "test_help";
	int theLength = test_getLength(theString);
	
	printf("[MAIN]. The length of the string <%s> is <%d>\n", theString, theLength);
	
	char *theTestString = "aTSLb1246";
	int theCount = test_getLowercaseAlphabetCount(theTestString);
	
	printf("[MAIN]. The count of the string <%s> is <%d>\n", theTestString, theCount);

	return 0;
}
