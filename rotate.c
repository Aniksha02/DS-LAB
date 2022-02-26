#include <stdio.h>
#include <stdlib.h>
struct node {
      int val;
      struct node *next;
  };
  struct node *head=NULL;

    void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
      
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->val);
        temp->next=NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void rotate()
{
     struct node* temp=head,*ptr;
     while(temp->next!=NULL)
     {    ptr=temp;
          temp=temp->next;
     }
     ptr->next=NULL;
     temp->next=head;
     head=temp;
     
}
void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->val);
        temp=temp->next;
    }
    printf("\n");
    
    
}

int main(){
    int ch,n;
    while(1){
        printf("\n1. make a list");
        printf("\n2. reverse");
      printf("\n3.display");
        printf("\n CHOOSE: ");
        scanf("%d",&ch);
    
    switch(ch){
        case 1: create();
        break;
        case 2:printf("enter number of times to be rotated:");
          scanf("%d",&n);
         for(int i=0;i<n;i++)
     rotate();
     display();
        break;
     
        default:printf("wrong");
        break;
    }
    }
    return 0;
}
     

    

