#include <stdio.h>
#include<stdlib.h>
#define SIZE 10


int A[SIZE];


int push ()
{
      int num;
      
      int top=-1;
      if (top == (SIZE - 1))
      {
            printf ("Stack is Full\n");
            return 0;
      }
      else
      {
            printf ("\nEnter element to be pushed : ");
            scanf ("%d", &num);
            top = top + 1;
            A[top] = num;
      }
      return 0;
}

int pop ()
{
      int num;
      int top = 0;
      if (top == - 1)
      {
            printf ("Stack is Empty\n");
            return 0 ;
      }
      else
      {
            num = A[top];
            printf (" element to pop is = %d\n", A[top]);
            top = top - 1;
      }
       return A[top];
}
    
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
              
    
