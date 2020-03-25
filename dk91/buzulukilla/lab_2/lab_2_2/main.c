#include "lab_2_tool.h"



int main(int argc, char** argv) {

int	flag,y,x,pointer,MASS[10],MASS_SORTED[10];
		



		
		for(y=0;y<10;y++){
			
		MASS[y]= random_MASS(y);	
		
				
		}
		
		
//		for(y=0;y<10;y++){
//			
//		printf(" %i",MASS[y]);	
//				
//		}
//		
//	printf("\n");	
	
						//бульбашка
/*	do{	flag=0;
		
		for(y=0;y<9;y++)
		{
		int parse=MASS[y];
			int poriv=porivnyannya(parse,MASS[y+1]);
			if (poriv==1)
			{
				flag=1;
				MASS[y]=MASS[y+1];
				MASS[y+1]=parse;
			}
		}
		
															
	}while(flag!=0);
	*/
/*	y=0;				//вибір
	do{
		
		int parse_1=MASS[y];
	for (x=0;x<10;x++){
		
	
		
	int poriv=porivnyannya(parse_1,MASS[x]);
	
	if (poriv==1 && MASS[x]<200){
		pointer=x;
		parse_1=MASS[x];
		}
		
	}
		MASS[pointer]=200	;
		MASS_SORTED[y]=parse_1;
	printf(" |%d| ",parse_1);
		y++;


	
}while (y<10);
	*/
	
swap(*MASS[],1,0);


//	printf("\n ");
//	printf("%i",MASS_SORTED);
	printf("\n ");
	printf("%i",MASS);
	
for(y=0;y<10;y++){
			
		printf(" %i",MASS_SORTED[y]);	
				
		}
printf("\n ");
for(y=0;y<10;y++){
			
		printf(" %i",MASS[y]);
//
}
return 0;
}
	

