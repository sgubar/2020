//
//  main.c
//  LaboratoryWork3
//
//  Created by Nazar Diadiun on 20.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include <stdio.h>
#include "Functions.h"

int main(int argc, const char * argv[])
{
    long ArraySize = getCharacterCount();
    
    shellsort(fileprocess(ArraySize), ArraySize);
    
    return 0;
}

