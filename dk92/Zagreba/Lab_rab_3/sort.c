#include "sort.h"


int dlina(){
    FILE *myfile;
    myfile = fopen ("hello.txt", "r");
    int b;
    fseek(myfile,0,SEEK_END);
    b=ftell(myfile);
    fclose(myfile);
    printf("Dlina v poryadke %i\n",b);
    return b;
}


char schit_iz_fila(int b,char *read){
    printf("Schital nachal\n");
    FILE *myfile;
                                                        printf("Schital nachal-1\n");
    myfile = fopen ("hello.txt", "r");
                                                            printf("Schital nachal-2   %i\n",b);
//    char readMMM[b];
                                                            printf("Schital nachal-3\n");
    fseek(myfile,0,SEEK_SET);
                                                            printf("Schital nachal-4\n");
    fgets (read, b, myfile);
                                                            printf("Schital nachal-5\n");
    fclose(myfile);
     /*                                                       printf("Schital nachal-6\n");
    for(int i=0;i<b;i++){
        read[i]=readMMM[i];
    }
*/
    printf("Schital\n");
}


int bikvi(int b,char *read,char a[]){
    printf("Bukvy nachal\n");
    int c=0;
    for(int i=0; i<b; i=i+1){
        if(isalpha (a[i])){
            //*read[c]=a[i];
            read[c]=a[i];
            c++;
        }
    }
     printf("Bukvy             %i\n",c);
   return c;
}


int zapis(int b,char *read){
    printf("zapis nachal\n");
    FILE *file;
    file = fopen("Rezult.txt", "w");
    for(int i=0; i<b; i++){
            //fprintf(file,"  %c \n",*read[i]);
            fprintf(file,"  %c \n",read[i]);
        }

    fclose(file);
        printf("zapis \n");
}

int poisk(char pisk,char *read,int b)
{          // printf("1\n");
    int a=0;
           // printf("2 a = %i\n",a);
    for(int i=0;i<b;i++){
          //  printf("3 i = %i     %c\n",i,read[i]);
        if(read[i]==pisk){
            a=i;
          //  printf("4 a = %i\n",a);
            return a;
        }
    }

     return NULL;

}






int partitionIt(char anArray[], int aLeftIndex, int aRightIndex, char aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;

	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] > aPivot);//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		// search the lowest element
		while (theRight > 0 && anArray[--theRight] < aPivot);//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		if (theLeft >= theRight) //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.// pointer are the same
		{
			break;
		}
		else
		{
			//lets to swap elements
            //не использовал swap из-за скорости
			char theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	//lets to swap elements
	char theTmp = anArray[theLeft];//зачем???
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;

	return theLeft; // return break position
}


void quickSort(char anArray[], int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}

	char thePivot = anArray[aRightIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

	//left part sorting
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

	//right part sorting
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}














/*
static void swap(char anArray[], int aLeftIndex, int aRightIndex);
static int mediana(char anArray[], int aLeftIndex, int aRightIndex);
static int m_partitionIt(char anArray[], int aLeftIndex, int aRightIndex, char aPivot);
static void m_manualSort(char anArray[], int aLeftIndex, int aRightIndex);
*/


/*
void swap(char anArray[], int aLeftIndex, int aRightIndex)
{
	char theTmp = anArray[aLeftIndex];
	anArray[aLeftIndex] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
}
*/





/*
int mediana(char anArray[], int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;

	if (anArray[aLeftIndex] > anArray[theCenter])
	{
		swap(anArray, aLeftIndex, theCenter);
	}

	if (anArray[aLeftIndex] > anArray[aRightIndex])
	{
		swap(anArray, aLeftIndex, aRightIndex);
	}

	if (anArray[theCenter] > anArray[aRightIndex])
	{
		swap(anArray, theCenter, aRightIndex);
	}

	swap(anArray, theCenter, aRightIndex - 1);

	return anArray[aRightIndex - 1];
}
*/
/*
int m_partitionIt(char anArray[], int aLeftIndex, int aRightIndex, char aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex - 1;

	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);

		// search the lowest element
		while (anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same
		{
			break;
		}
		else
		{
			//lets to swap elements
			swap(anArray, theLeft, theRight);
		}
	}

	//lets to swap elements
	swap(anArray, theLeft, aRightIndex - 1);

	return theLeft; // return break position
}
*/
/*
void m_manualSort(char anArray[], int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 1)
	{
		return;
	}

	if (2 == theSize)
	{
		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		// 3 elementes
		if (anArray[aLeftIndex] > anArray[aRightIndex - 1])
		{
			swap(anArray, aLeftIndex, aRightIndex - 1);
		}

		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}

		if (anArray[aRightIndex - 1] > anArray[aRightIndex])
		{
			swap(anArray, aRightIndex - 1, aRightIndex);
		}
	}
}
*/

/*
void quickSort2(char anArray[], int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 3)
	{
		m_manualSort(anArray, aLeftIndex, aRightIndex);
	}
	else
	{
		int thePivot = mediana(anArray, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

		//left part sorting
		quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

		//right part sorting
		quickSort(anArray, thePartitionIndex + 1, aRightIndex);
	}
}

*/
