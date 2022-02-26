#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
//struct node* head=NULL;
struct node* newNode;
void insert(struct node* *head,int val)
{   newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->data=val;
    newNode->next=NULL;
    
    if((*head)==NULL)
    {
        (*head)=newNode;
        return;
    }
    struct node* temp=(*head);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    
    
}


struct node*concatanation(struct node* h1,struct node* h2)
{
    struct node*temp=(h1);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=h2;
    return h1;
}

void display(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {   printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}

int main()
 {   struct node* head1=NULL;
     struct node* head2=NULL;

    int val,ch,x;
    printf("Enter.\n1.insert into linked list\n2.concatanationof two linked lists\n3.display\n4.Exit");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter 1.Insert in first linked list\n2.Insert in second linked list\n");
                scanf("%d",&x);
                printf("Enter the element:");
                scanf("%d",&val);
                if(x==1)
                {
                    insert(&head1,val);
                }
                else if(x==2)
                {
                    insert(&head2,val);
                    
                }
                break;
                
            case 2: printf("Two lists are concatanated:");
                head1=concatanation(head1,head2);
            
                break;
               
            case 3:    display(head1);
               break;
            case 4:
           
                exit(0);
                break;
                
        }
    }

    return 0;
}
