//
//  main.c
//  dz1_2
//
//  Created by Slava Gubar on 3/5/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "tool.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	printf("Hello, World!\n");
	
	printf("num of uppercase symbols: %d\n", get_numOfUpercaseSymbols("Hello, World"));
	printf("num of uppercase symbols: %d\n", get_numOfUpercaseSymbols("HEllO, World"));
	printf("num of uppercase symbols: %d\n", get_numOfLowercaseSymbols("HEllO, World"));
	
	char *myStr = "my str";
	
	printf("num of uppercase symbols: %d\n", get_numOfLowercaseSymbols(myStr));
	
	myStr = NULL;
	printf("num of uppercase symbols: %d\n", get_numOfLowercaseSymbols(myStr));

	return 0;
}
