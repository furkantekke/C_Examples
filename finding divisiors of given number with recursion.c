
#include<stdio.h>

int find(int b,int a)
{
	if(b%a==0)
		printf("%d ",a);
		
		while(a<b)
			return find(b,a+1);
    
}

int main()
{
    int n,i=1;
    
    printf("Please entry your number want to find divisors : \n");
    
    scanf("%d", &n); 
    
    find(n,i);
    
    puts("");
    
    return 0;
}

