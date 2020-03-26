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
	
//	void swap1(int *mass[],int x,int y)
//	{
//		int temp=*mass[x];
//		*mass[x]=*mass[y];
//		*mass[y]=temp;
//		
//	}
//	





//_________________________________
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}



void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
