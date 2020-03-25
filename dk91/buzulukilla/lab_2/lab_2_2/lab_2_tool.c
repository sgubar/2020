#include "lab_2_tool.h"



int random_MASS(int A){

srand(A);
	
	int	random;
int flag;	
do{	
flag=0;	
random=64+rand()%56;
		
		
	if(random>90 && random<97){
		flag++;
	}
		
}while(flag==1);

	return random;						
		
	}
	
	int porivnyannya(int A, int B){
		if (A>B )
		{
			return 1;
		}
		else
		if (A<B || A==B)
		{
			return 0;
		}
	}
	
	void swap(int *mass[],int x,int y)
	{
		int temp=*mass[x];
		*mass[x]=*mass[y];
		*mass[y]=temp;
		
	}
	
