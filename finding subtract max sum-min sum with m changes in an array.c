
#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int i,num,j,temp,change,eb=0,ek=0,test,counter=0,sub;
	
	printf("How many tests in program: ");	scanf("%d",&test);
	while(counter<test){
	
	
	printf("How many elements will be in our array: ");	scanf("%d",&num);
	
	int arr[num];
	
	
	
	for(i=0;i<num;i++){
		printf("%d. degeri giriniz: ",i+1);	scanf("%d",&arr[i]);}

//to find max sum your array is sorting
for(i=0;i<num;i++){
	for(j=0;j<num-1;j++){
		if(arr[j]<arr[j+1]){
		temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
		}	}	}
	
	printf("Your array = ");
	for(i=0;i<num;i++){
		printf("%d",arr[i]);
	}
	puts("");  // TO ADD NEW LİNE FOR CLEAR OUTPUT
	
	printf("How many changes will be : ");	scanf("%d",&change);
	
  while(num<change){
		printf("You can't make more changes to your array size \n");
			printf("How many changes will be : ");	scanf("%d",&change);
	}
	
	//your array already sorted 
  //to finding min sum you started adding elements from arr[change] to arr[num] 
	for(i=change;i<num;i++){
		ek+=arr[i];
	}
	
  //to finding max sum you started adding elements from 0 to arr[num-change]  
  
	for(i=0;i<num-change;i++){
		eb+=arr[i];
	}
	
	printf("Min sum of the %d changes from the array = %d\n",change,ek);
	
	printf("Max sum of the %d changes from the array = %d\n",change,eb);
	
	
	sub=eb-ek;
	printf("max sum difference with the min sum = %d\n",sub);
	
	counter++;
	ek=0;
	eb=0;
	sub=0;
	}
	
	
	
	return 0;
}
