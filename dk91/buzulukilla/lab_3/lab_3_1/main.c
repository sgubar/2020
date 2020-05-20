#include "lab_3_tool.h"


int main(int argc, char** argv) {


 int *arr;	
 
 unsigned long x,y;

	printf("enter size of arr\n");
		scanf("%lu",&x);
	
		
		
	arr = (int*)malloc(x * sizeof(int));
	
	
printf("\n_____________\n ");
	
		for(y=0;y!=x;y++)
		{	
			arr [y]	 =	rnd(y);
	printf("%c ",arr[y]);
		
		}	
	
	

double start = clock();
  	
	  
	  qsort(arr,  x, sizeof(int),(int(*) (const void*, const void*))comp);
  
int fin=clock();	
	
	


	printf("\ntime of sort:%.6lf\n", (fin - start) / CLOCKS_PER_SEC);

	for(y=0;y!=x;y++)
		{	
			printf("%c ",arr[y]);
		}





/*binsearch*/
unsigned long b=x;
char flag;
int  quest='A';
flag=menu();
			
			
			
if (flag==0){
//	{
		fflush(stdin);
		printf("enter what LETTER you searching:\n");
		scanf("%c",&quest);
		printf("\n|||%c",quest);	
			
//			}while(quest<'a'&&quest>'z'&&quest<'A'&&quest>'Z');
			
}	
		
	
unsigned long result = binarySearch(arr,x,quest) ;
	
	printf("%lu",result);
	
	free(arr);
	
	return 0;
}
