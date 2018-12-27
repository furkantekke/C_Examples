
// Our aim is saving max patient

#include <stdio.h>

void main(){
	
	int i,j,n,a,b,say=0;
	
	printf("How many vaccines ? ");	scanf("%d",&n);
	
	while(n>10){
		printf("Our vaccine num is max 10.\n");
		printf("How many vaccines ? ");	scanf("%d",&n);
		}
		
	int vaccines[n];
	int patients[n];
	
	printf("Vaccines anti-x numbers: \n");
	
		for(i=0;i<n;i++){
			scanf("%d",&vaccines[i]);
			}
				
	printf("Patients x virus numbers: \n");
		
		for(i=0;i<n;i++){
			scanf("%d",&patients[i]);
			}
	
	//buble sort for vaccines
	for(i=0;i<n-1;i++){		
		for(j=0;j<n-i-1;j++){
			if(vaccines[j]>vaccines[j+1]){
				a=vaccines[j];
				vaccines[j]=vaccines[j+1];
				vaccines[j+1]=a;
				}
			}
		}
		
	// buble sort for patients
	for(i=0;i<n-1;i++){		
		for(j=0;j<n-j-1;j++){
			if(patients[j]>patients[j+1]){
				b=patients[j];
				patients[j]=patients[j+1];
				patients[j+1]=b;
				}
			}
		}
		
		printf("Sorted vaccines arr from anti x viruses = ");
		 for (i = 0; i < n; i++){
			printf("- %d-  ", vaccines[i]);}	puts("");
			
		printf("Sorted patients arr from x viruses = ");
		 for (i = 0; i < n; i++){
			printf("- %d-  ", patients[i]);}	puts("");
				
			
	
	for(i=0;i<n;i++){
		if(vaccines[i]>=patients[i]){
			say+=1;
			}
		}
		
		if(say==n)
			printf("All patients are saved.");
			
		else
			printf("%d patient saved.",say);

	}
