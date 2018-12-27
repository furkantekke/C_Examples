#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 


int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // small element index

	for (int j = low; j <= high- 1; j++) 
	{ 
  
		//if our element less equal the pivot
    
		if (arr[j] <= pivot) 
		{ 
			i++; // less element index
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 


void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 

		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

//for print arr
void print(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
} 


int main() 
{   
	int question,i,size,b;
	printf("How many element will be in our array ? "); scanf("%d",&size);
	int arr[size];
	
	
	for(i=0;i<size;i++){
		printf("please entry the %d. element: ",i); scanf("%d",&arr[i]);
		}
		
		printf("Your question number: ");	scanf("%d",&question);
	quickSort(arr, 0, size-1); 
	printf("Sorted array: "); 
	print(arr, size); 
	
	puts("");
	b=question+1;
	
	
	for(i=0;i<size;i++){
		if(b == arr[i]){b=b+1;}
			}
		printf("Your result is  = %d",b);
			return 0; 
			
			}
		
		
		
	
	
