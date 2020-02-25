#include "dk_tool.h"

int str_find(char *inString, char *aString)
{
	
	if(NULL == inString || NULL == aString || '\0' == aString[0])
		return -1;
	int i,j;
	for(i = 0, j = 0; inString[i] != '\0';i++)
		if(str_help(inString, aString, i) == 1)
			j++;
	return j;
}

int str_help(char *inString, char *aString,int start)
{
	int i = 0, j = 0;
	for(i = start, j = 0; inString[i] == aString[j]; j++, i++);
	return aString[j] == '\0' ? 1 : 0;
}
