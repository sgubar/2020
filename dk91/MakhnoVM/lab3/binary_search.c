#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

void binarySearch(char* key, char** k, int left, int right)
{
	int search = -1;
	while (left <= right) 
	{
    	int mid = (left + right) / 2; 
    		if (strcmp(key,k[mid]) == 0) {  
     	 	search = mid;     
     		 break;            
    	}
    	if (strcmp(key,k[mid]) < 0)     
      		right = mid - 1;  
    	else                  
      		left = mid + 1;   
 	}
  	if (search == -1) printf("Элемент не найден!\n");    
   	else   printf("number %d", search);       
    
}