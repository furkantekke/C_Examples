
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

struct StackNode 
{ 
    int data; 
    struct StackNode* next; 
}; 
  
struct StackNode* newNode(int data) 
{ 
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(struct StackNode *root) 
{ 
    return !root; 
} 
  
void push(struct StackNode** root, int data) 
{ 
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
} 


  
int pop(struct StackNode** root) 
{ 
    if (isEmpty(*root)) 
        return INT_MIN; 
    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp); 
  
    return popped; 
} 
  
int peek(struct StackNode* root) 
{ 
    if (isEmpty(root)) 
        return INT_MIN; 
    return root->data; 
} 
  
int main() 
{ 
    struct StackNode* root = NULL;
    struct StackNode* temp2 = NULL;
    struct StackNode* temp3=NULL;
    struct StackNode* temp4=NULL;
    
    int test,kapasite,i=0,j=0,x,y,eleman,gecici1,gecici2,say=0,gecici3,a=0,gecici4;
    
    printf("\nWelcome   :)\n\n");
    
    printf("Give the test number ");	scanf("%d",&test);
    
    while(i<test){
	 printf("How many tower to be ");	scanf("%d",&kapasite);
	 
	 while(j<kapasite){
		printf("length of towers ");	scanf("%d",&eleman);
		push(&root,eleman);
		push(&temp2,eleman);
		j++;		 	}
	 
	 
	 for(x=0;x<kapasite-1;x++){
		 
		 gecici1=peek(root);
		 pop(&root);
		 
		 for(y=0;y<kapasite-x-1;y++){
			 
			 gecici2=peek(temp2);
			 if(gecici1>=gecici2){ say++;}
			 pop(&temp2);
			 gecici3=peek(temp2);
			 push(&temp3,gecici3);
		 
		 }
		 while(a<kapasite-x-1){
			 
			 gecici4=peek(temp3);
			  push(&temp4,gecici4);
			pop(&temp3);
			
			 a++;}
			 a=0;
			 if(gecici1>=gecici3){say++;}
			 temp2=temp4;
			 puts("");
			 puts("*******************************************");
			 printf("sign made from tower %d   = %d\n",gecici1,say);
			 puts("*******************************************");
		say=0;
		 
			 }
			 
			
	  i++;
		 
		 }
		 
		 puts("");
	 puts("*******************************************");
	 printf("sign maded from tower %d = 1\n",peek(root));
	 puts("*******************************************");
	
	 
  
    return 0; 

}
