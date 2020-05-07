#include "dz_1_tool.h"

//int mult(int A,int B)
//{
//	int c;
//	c=A*B;
//	return c;
//}


int random(void){

srand(1);
	
	int	random;
int flag;	
	
flag=0;	
random=rand();
	return random;						
		
	}
	
int outpt_matrix(int*mass,int x,int y)
{
	
		for(;x==0;x--)
	{
		for(;y==0;y--)
		{
			printf("/%i|"mass[x][y]);
		}
	}
	return 0;
}	
