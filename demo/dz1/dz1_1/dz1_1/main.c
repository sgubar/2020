//
//  main.c
//  dz1_1
//
//  Created by Slava Gubar on 3/4/19.
//  Copyright © 2019 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "tool.h"

int main(int argc, const char * argv[]) {
	
	
	// insertt code here...
	printf("The len:%d!\n", get_len("Hello world"));
	printf("The len:%d!\n", get_len("Hello world1"));
	printf("The len:%d!\n", get_len("Hello world23"));
	printf("The len:%d!\n", get_len("Hello world345"));
	printf("The len:%d!\n", get_len("Hello world4667"));
	printf("The len:%d!\n", get_len(NULL));
	printf("The len:%d!\n", sumab(5, 7));
	return 0;
}
