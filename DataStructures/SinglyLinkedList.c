#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

int data;
struct node* next;

}node;


node* createLlist(int val);

void printList(node* head);
bool searchList(node* head,int key);
node* deleteKey(node* head,int key);
node* deletePosition(node* llist);
void freeList(node* head);


void insertAtFirst(node** head, int val); 
void insertAtEnd(node** head, int val);
void insertAtPosition(node** head, int val, int position);
void deleteFromFirst(node** head);
void deleteFromEnd(node** head);
void deleteAtPosition(node** head, int position);


int main(){
    return 0;
}


node* createLlist(int val){
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode == NULL) return NULL;

    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}




void printList(node* head){

node* temp = head;
if(temp== NULL || head == NULL) return;

while(temp!=NULL){

printf("%d ",temp->data); 
temp=temp->next;

}

}


bool searchList(node* head,int key){
if(head == NULL) return false;
node* temp=head;
while(temp!=NULL){
    if(temp->data == key) return true;
    temp=temp->next;
}
   
return false;



}

node* deleteKey(node* head,int key){

if(head==NULL)  return head;

//one node and key suits 
if(head->data == key){
    deleteFromFirst(&head);
    return head;
}


node* temp = head;

while(temp->next != NULL){
    if(temp->next->data == key){
        node* target = temp->next;
        temp->next = target->next;
        free(target);
        return head;
    }    

temp = temp->next;

}



return head;
}



void freeList(node* head){
    if(head==NULL) return;

    while(head!=NULL){
        node* prev = head;
        head=head->next;
        free(prev);

    }

}


void insertAtFirst(node** head, int val){
    //address error
if(head==NULL) return;

node* newNode=createLlist(val);
if(newNode == NULL) return;

newNode->next = *head;
*head=newNode;

}




void insertAtEnd(node** head, int val){



node* newNode=createLlist(val);
if(newNode == NULL) return;

if(*head==NULL){
*head = newNode;
return;
}

node* temp  = *head;
while(temp->next!=NULL){
temp=temp->next;

}
temp->next = newNode;


}




void insertAtPosition(node** head, int data, int position){
    
    
    if (position == 0){
        insertAtFirst(head,data);
        return;
    }
    

    node* temp = *head;
    int i=0;

    while(temp!=NULL && i<position-1){
        temp=temp->next;
        i++;
    }
    //reaches end before position
    if(temp==NULL) return;

    node* newNode = createLlist(data);
    if(newNode == NULL) return; 


    newNode->next=temp->next;
    temp->next=newNode;



}





void deleteFromFirst(node** head){
if(head == NULL || *head == NULL) return;

if((*head)->next == NULL){
    free(*head);
    *head = NULL;
    return;
}

node* temp = *head;
(*head)=temp->next;
free(temp);
}



void deleteFromEnd(node** head){





    
if(head == NULL || *head == NULL) return;


if((*head)->next == NULL){
    free(*head);
    *head = NULL;
    return;
}


node* temp=*head;
node* prev = NULL;



while(temp->next != NULL){
prev = temp;
temp = temp->next;


}
if(prev != NULL) prev->next = NULL;

free(temp);
temp = NULL;


}





void deleteAtPosition(node** head, int position){
if((*head) == NULL || head == NULL) return;
if(position == 0){
    deleteFromFirst(head); 
    return;
}


node* temp = *head;

//to reach prev position of wanted llist
for(int  i=0; i < position - 1 && temp !=NULL;i++){
    temp = temp->next;
}

if(temp == NULL || temp->next == NULL) return;

node *toDelete = temp->next;
temp->next = toDelete->next;
free(toDelete);





}



