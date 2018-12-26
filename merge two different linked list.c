

#include<stdio.h>
#include<stdlib.h>




///////////////// The Application is merging two different default linked list in third linked list  ///////////////

struct node {
int data;
struct node *next;
};


//////////////////// adding node function /////////////////////////////


void insert_node(struct node **head,int no){
    struct node *p,*r;
 
    if(*head==NULL){
        p=(struct node *)malloc(sizeof(struct node));
        p->data=no;
        p->next=NULL;
        *head=p;
    }
    else{
        p=*head;
        while(p->next!=NULL)
            p=p->next;
        p->next=(struct node *)malloc(sizeof(struct node));
        p=p->next;
        p->data=no;
        p->next=NULL;
    }
} 



///////////////// printing linked list function ////////////////////////////////
void print(struct node *head)
{
    struct node *p;
    p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
} 

/////////////// merge function /////////////////////

void merge(struct node **ptr1,struct node **ptr2,struct node **ptr3){
    struct node *gecici;
    if(*ptr2==NULL && ptr1!=NULL){
        *ptr3=*ptr1;
        return;
    }
    else if(*ptr1==NULL && ptr2!=NULL){
        *ptr3=*ptr2;
        return ;
    }
    else if(*ptr1==NULL && ptr2==NULL){
        return;
    }
    *ptr3=*ptr1;
    gecici=*ptr1;
    while(gecici->next!=NULL)
        gecici=gecici->next;
        gecici->next=*ptr2;
}


////////////////// main funct. ////////////////////////////

int main(){
    struct node *ptr1,*ptr2,*ptr3=NULL;
    ptr1=ptr2=NULL;
    
    
    printf("First List : ");
    insert_node(&ptr1,1);
    insert_node(&ptr1,2);
    insert_node(&ptr1,3);

    print(ptr1);
    
    
    
    printf("\nSecond List : ");
    insert_node(&ptr2,6);
    insert_node(&ptr2,7);
    insert_node(&ptr2,8);
    insert_node(&ptr2,9);
    
    print(ptr2);
    
    
    
    
    printf("\n Result :");
   merge(&ptr1,&ptr2,&ptr3);
    print(ptr3);
    return 0;
}
 


