

#include <stdio.h>

#include <stdlib.h>


typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *head;
int count=0;

node* create_node(int x){
    node *new_node;
    new_node = (struct node *)malloc(sizeof(node));
    new_node -> data = x;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    return new_node;
}


void at_beg(int x){
    node *new_node;
    new_node = create_node(x);
    if(head==NULL)
    head = new_node;
    else{
        new_node -> next = head;
        head -> prev = new_node;
        head = new_node;
    }
}

void at_end(int x){
    node *new_node;
    new_node = create_node(x);
    node *temp;
    if(head == NULL)
    head = new_node;
    else{
        temp = head;
        while((temp -> next) != NULL)
        temp = temp -> next;
        temp -> next = new_node;
        new_node -> prev = temp;
    }
}

void at_position(int x, int pos){
    node *new_node;
    int i;
    new_node = create_node(x);
    node *temp;
    temp = head;

    for(i=1; i < (pos-1); i++)
    temp = temp -> next;

    new_node -> next = temp -> next;
    new_node -> prev = temp;
    temp -> next = new_node;
    new_node -> next -> prev = new_node;
}

void del_beg(){
    node *ptr;
    if(head==NULL)
    printf("List is Empty");
    else if(head -> next == NULL){
        free(head);
        head = NULL;
    }else{
        ptr = head;
        head = head -> next;
        free(ptr);
        head -> prev = NULL;
    }
}

void del_end(){
    node *temp = head;
    if(head==NULL){
        printf("List is Empty");
    }else if(head -> next == NULL){
        free(head);
        head = NULL;
    }else{
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> prev -> next = NULL;
        free(temp);
    }
}

void del_position(int pos){
    int i;
    node *temp = head;
    for(i = 1; i < pos; i++)
        temp = temp -> next;
    
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(temp);
}

void display(){
    node *temp;
    temp = head;
    if(count == 0)
    printf("The List is Empty!!");
    else{
        printf("The linked list is: \n");
        while(temp != NULL){
            printf("%d \n", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int c1, x, pos;
    while(1){
    printf("Please make your choice: \n");
    printf("1. Insert at beginning \t 2. Insert at end \t 3. Insert at any position \n4. Delete at beginning \t 5. Delete at end \t 6. Delete at any position \n7. Display\t 8. Exit \n");
    scanf("%d", &c1);
    switch(c1){
                    case 1:{            
                        printf("Enter the value to be added to the list: ");
                        scanf("%d", &x);
                        at_beg(x);  
                        count++;
                    }
                    break;
                    case 2:{            
                        printf("Enter the value to be added to the list: ");
                        scanf("%d", &x);
                        at_end(x);
                        count++;
                    }
                    break;
                    case 3: {            
                        printf("Enter the value to be added to the list: ");
                        scanf("%d", &x);
                        printf("Enter the position at which the data is to be added: ");
                        scanf("%d", &pos);
                        if(pos == 1)
                        at_beg(x);
                        else if(pos == count+1)
                        at_end(x);
                        else
                        at_position(x, pos);
                        count++;
              
        }break;
                    case 4: {
                        del_beg();
                        count--;
                    }
                    break;
                    case 5: {
                        del_end();
                        count--;
                    }
                    break;
                    case 6: {
                        printf("Enter the position from where you want to delete: ");
                        scanf("%d", &pos);
                        if(pos == 1)
                        del_beg(x);
                        else if(pos == count)
                        del_end(x);
                        else
                        del_position(pos);
                        count--;
                    }
                    break;
                    case 7: display();
                    break;
        case 8: exit(0);
        default: printf("Please enter a valid choice");
        break;
        }
    }
    
    return 0;
}
