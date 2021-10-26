#include <stdio.h>
#include<stdlib.h>
#define SIZE 100

void push(int);
void pop();
void display();


int stack[SIZE], top=-1;

void main()

{
    int value,choice;
    while(1){
        printf("\nMENU\n");
        printf("1.push\n2.pop\n3.display\n4.exit");
printf("\nenter your choice:");
scanf("%d", &choice);
switch(choice){

    case 1:printf("enter the value to be inserted");
    scanf("%d",&value);
    push(value);
    break;
    case 2:pop();
    break;
    cas 3:display();
    break;
    case 4: exit(0);
    default:printf("\nwrong selection, try again");
}
    }
}

void push (int value)
{
      if (top == (SIZE - 1))
      {
            printf ("Stack is Full\n");  
      }
      else
      {
          top++;
          stack[top]=value;
            printf ("\ninsertion success");}
}

void pop ()
{
      if (top == - 1)
      {
            printf ("Stack is Empty\n");
           
      }
      else
      {
            printf("\ndeleted:%d",stack[top]);
            top--;
      }
       
}
    void display(){

        if(top==-1)
        printf("stack is empty");
        else
        {
            int i;
            printf("\nsack elements are:\n");
            for(i=top;i>=0;i--)
            printf("%d\n",tack[i]);
        }

        }
