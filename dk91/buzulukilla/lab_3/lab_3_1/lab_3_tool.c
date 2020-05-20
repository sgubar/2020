#include "lab_3_tool.h"


void swap(int*px, int*py) 
{int temp;
temp = *px;
*px = *py;
*py= temp;}



int rnd(int A){

srand(time(NULL)+A);
	
	int	random;
int flag;	
do{	
flag=0;	
random=65+rand()%56;
		
		
	if(random>90 && random<97){
		flag++;
	}
		
}while(flag==1);

	return random;						
		
	}
	
	int comp (const int *i, const int *j)
{
return *i - *j;
}

char menu(void)
{
	char a=1,flag=1;
while (a!=0){
fflush(stdin);

printf("did you search something? Y/N\n");
	
char ask = 0;
	
		scanf("%c",&ask);
		
		if (ask=='n' || ask=='N')			
			a=0;
			
			
		else 
		if (ask=='y'||ask=='Y'){
			a=0;
			flag=0;
}
	}
	return flag;
}


unsigned long binarySearch(int  arr[], long unsigned x, char target) 
{ 
    if (x > 1) { 
          		 printf(" %lu |%i |%i ",x, arr[x-1],target); 	
        
        if (arr[x] == target)
            return x;   
              
        if (arr[x] > target) 
            return binarySearch(arr,x-x/2,target) ;

        if (arr[x] < target)
        return binarySearch(arr,x+x/2,target); 
     }

	return -1;
}
