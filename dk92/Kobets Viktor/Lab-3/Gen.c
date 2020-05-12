#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Gen.h"


void genFile(char* name, int length)
{
	FILE *rezultFILE;
	rezultFILE = fopen(name, "w");
	time_t t;
	srand((unsigned) time(&t));
	char a;
	for(int i=0; i < length; i++)
	{
    	if(rand()%2){
  			a = (rand()%26)+65;
		}
		else{
  			a = (rand()%26)+97;
		}
    	fwrite(&a, sizeof(a), 1, rezultFILE);
	}
	fflush(rezultFILE);
	fclose(rezultFILE);
}