\\. Implement a Doubly linked list program to store Facebook friend list (name, mobile number, likes) and display friend details having the highest number of likes.
#include <stdio.h>
#include <stdlib.h>

struct node{
struct node *prev;
char name[10];
long int mobile;
int likes;
struct node *next;
};

struct node *head=NULL;

struct node* createNode(){
struct node* newNode;    
newNode=(struct node*)malloc(sizeof(struct node));
newNode->next=NULL;
newNode->prev=NULL;
return newNode;
}

void push(){
struct node *newNode=createNode();
printf("Enter Name: ");
scanf("%s",newNode->name);
printf("Enter Mobile No.: ");
scanf("%ld",&newNode->mobile);
printf("Enter Likes.: ");
scanf("%d",&newNode->likes);
if(head==NULL){
head=newNode;
}
else{
head->prev=newNode;
newNode->next=head;
head=newNode;
}
}

void append(){
struct node *newNode=createNode();
printf("Enter Name: ");
scanf("%s",newNode->name);
printf("Enter Mobile No.: ");
scanf("%ld",&newNode->mobile);
printf("Enter Likes.: ");
scanf("%d",&newNode->likes);
if(head==NULL){
head=newNode;
}
else if(head->next==NULL){
newNode->prev=head;
head->next=newNode;
}
else{
struct node *temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
newNode->prev=temp;
temp->next=newNode;
}
}

struct node* highestLikes(){
struct node *head1=head;
struct node *largest=head;
while(head1!=NULL){
if(head1->likes>largest->likes){
largest=head1;
}
head1=head1->next;
}
return largest;
}

int main(){
struct node *newNode =createNode();
int i,a;
printf("enter number of entries");
scanf("%d",&a);
for(i=0;i<a;i++){
printf("Enter the details of Friend%d\n",i+1);
push();
}

struct node *largest=highestLikes();
printf("*Details of highest liked friend*\n");
printf("Name :%s\n",largest->name);
printf("Mobile Number :%ld\n",largest->mobile);
printf("Likes :%d\n",largest->likes);
printf("*****\n");
return 0;
}
