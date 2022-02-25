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
      
