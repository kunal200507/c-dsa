//reverse a linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* reverseList(struct Node* head){
    struct Node* prev=NULL;
    struct Node* curr=head;
    struct Node* nex=head->next;
    while(curr!=NULL){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}

void traverse(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("element : %d\n",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct Node* head= (struct Node*)malloc(sizeof(struct Node));
    struct Node* two= (struct Node*)malloc(sizeof(struct Node));
    struct Node* three= (struct Node*)malloc(sizeof(struct Node));
    struct Node* four= (struct Node*)malloc(sizeof(struct Node));
    struct Node* five= (struct Node*)malloc(sizeof(struct Node));
    
    head->data=15;
    head->next=two;
    two->data=16;
    two->next=three;
    three->data=17;
    three->next=four;
    four->data=18;
    four->next=five;
    five->data=19;
    five->next=NULL;
    
    // traverse(head);
    printf("\n");
    traverse(reverseList(head));
    
    return 0;
}