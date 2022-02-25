#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    int data;
};
struct node *head=NULL;

void create();
void reverse();
void display();

int main(){
    int ch;
    while(1){
        printf("\n1. make a list");
        printf("\n2. reverse");
      printf("\n3.display");
        printf("\n CHOOSE: ");
        scanf("%d",&ch);
    
    switch(ch){
        case 1: create();
        break;
        case 2:reverse();
        break;
       case 3: display();
       break;
        default:exit(0);
        break;
    }
    }
}

void display(){
    struct node *ptr;
    ptr=head;
    printf("linked list is :");
    while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr=ptr->next;
        
    }
}
     void create(){
         struct node *ptr,*temp;
         temp=(struct node*)malloc(sizeof(struct node));
         temp->next=NULL;
         
         printf("enter element: ");
         scanf("%d",&temp->data);
         
         if(head==NULL){
             head=temp;
         }
         else{
             ptr=head;
             while(ptr->next!=NULL)
             {
                 ptr=ptr->next;
             }
             ptr->next=temp;
         }
}

void reverse(){
  
    struct node *temp=NULL;
    struct node *temp1=NULL;
    
    while(head!=NULL){
      temp1=head->next;
      head->next=temp;
      temp=head;
      head=temp1;
    }
      head=temp;
      
    }
