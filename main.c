#include "lab_2_tool.h"



int main(int argc, char** argv) {

int	flag,counter,y,x,poriv,pointer1,flag_2, i=0;
int MASS[10000],ch;		

	printf("%i",counter);	
		;
	;
		
		
		FILE * pointer;
		
		pointer = fopen("D:\\example.txt", "r");
		
		 if (pointer == NULL)
    {
        printf("File is not available \n");
    }

		else
    {
       
        while ((ch = fgetc(pointer)) != EOF)
        {
        	 printf("%c", ch);
            counter++;
        }
    }
		
		fclose(pointer);
		
			
		
	FILE * _pointer;
		
		_pointer = fopen("D:\\examplee.txt", "r");
		
		 if (_pointer == NULL)
    {
        printf("File is not available \n");
    }

		else
    {
       
        while ((ch = fgetc(_pointer)) != EOF)
        {
        	
            MASS[i]= ch;
            i++;
        }
    }
		
		fclose(_pointer);
	
		
		


//int MASS_SORTED[counter];
//		
//		for(y=0;y<counter;y++){
//			
//		MASS[y]= random_MASS(y);	
//		
//		MASS_SORTED[y]=0;		
//		}
//		
//		
//		for(y=0;y<counter;y++){
//			
//		printf(" %i",MASS[y]);	
//				
//		}
//		
//		printf("\n");	
//		
//			for(y=0;y<counter;y++){
//			
//		printf(" %c",MASS[y]);	
//				
//		}printf("\n");	
	
	
	bubbleSort(MASS,counter) ;					//бульбашка людська 22.2 sec/100000
		
	
												//бульбашка 	46.17sec/100000
/*	do{	flag=0;
		
		for(y=0;y<counter-1;y++)
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
		
//		selectionSort(MASS,counter) ;			//вибір людський 13.77 sec/100000
		
		
/*	y=0;										//вибір sec 84.09/100000
	do{ 
		
		int parse_1=MASS[y];
	for (x=0;x<counter;x++){
		
	
		
	int poriv=porivnyannya(parse_1,MASS[x]);
	
	if (poriv==1 && MASS[x]<200){
		pointer=x;
		parse_1=MASS[x];
		}
		
	}
		MASS[pointer]=200	;
		MASS_SORTED[y]=parse_1;
//	printf(" |%d| ",parse_1);
		y++;


	
}while (y<counter);
	
	
//swap(*MASS,1,2);
*/

//insertionSort(MASS, counter);					//вставкою людський 9.166 sec/100 000

/*
for(y=0;y!=counter;y++)							//вставкою 11.62 sec/100 000
		{flag_2=0;		
			
																		
		
			int parse_2=MASS[y];
			
			 	
			 	MASS_SORTED[y]=parse_2;
															
				int z=y;
																
		do{ 	
//printf(" %i",flag_2);
//				for(x=0;x<10;x++){
//			
//		printf(" %i",MASS_SORTED[x]);	
//				
//		}
					if(z>0){
						 poriv=porivnyannya(MASS_SORTED[z-1],parse_2);
//				printf(" |%i /%i| (%i)",MASS_SORTED[z-1], parse_2,poriv);
				if (poriv>0){
//				printf(" \n");
					MASS_SORTED[z]=MASS_SORTED[z-1];
					MASS_SORTED[z-1]=parse_2;
				z--;
			}else
			{
				flag_2=1;
			}				
				}
				
				else{
//			printf(" |%i /%i| (%i)",MASS_SORTED[z-1], parse_2,poriv);
					MASS_SORTED[z]=parse_2;
				flag_2=1;
			}
				
		
				}while(flag_2<1);
			 	
			
			
		
		
		

		}


*/


//	for(y=0;y<counter;y++){
//			
//		printf(" %i",MASS_SORTED[y]);	
//				
//		}

			for(y=0;y<counter;y++){
			
		printf(" %i",MASS[y]);	
				printf(" %c",MASS[y]);	
		}
		
		
	printf("\n ");
	


return 0;
}

