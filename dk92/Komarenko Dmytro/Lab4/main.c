#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dk_tool.h"

int main()
{
    system("chcp 1251");
    system("cls");
	Node *theNode = NULL;
	FILE *afile = fopen("txt.txt","r");

	if (afile != NULL)
	{
		char symbol;
		while ((symbol = fgetc(afile)) != EOF)
		{
			if (isalpha(symbol))
			{
				while (isalpha(symbol))
				{
					theNode = add(theNode, symbol);
					symbol = fgetc(afile);
				}

				if (theNode != NULL)
				{
					print(theNode);
					del(theNode);
					theNode = NULL;
				}
			}

          printf("%c", symbol);
		}

		fclose(afile);
        }
	else
	{
		printf("Немає файлу\n");
		return 1;
	}

	return;
}
