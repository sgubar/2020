#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dk_tool.h"

int main()
{
	Node *theNode = NULL;
	FILE *afile = fopen("txt.txt","r");

	if (afile != NULL)
	{   //переменная, в которую поочередно будут помещаться считываемые байты
		char symbol;
		//чтение одного байта из файла
		//проверка на конец файла или ошибку чтения
		while ((symbol = fgetc(afile)) != EOF)
		{
			if (isalpha(symbol))
			{
				while (isalpha(symbol))
				{
					theNode = add(theNode, symbol);
					symbol = fgetc(afile);  //чтение одного байта из файла
				}
                //проверяем что именно произошло:кончился файл
                //или это ошибка чтения
				if (theNode != NULL)
				{
					print(theNode);
					del(theNode);
					theNode = NULL;
				}
			}
			//если файл не закончился, и не было ошибки чтения
			//выводим код считанного символа на экран
          printf("%c", symbol);
		}
		//закрываем файл
		fclose(afile);
        }
	else
	{
		printf("No file\n");
		return 1;
	}

	return;
}

