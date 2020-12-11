#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}Node;

Node* add(Node* head,int data){
    if(head==NULL){
        head=(Node*) malloc(sizeof(Node));
        head->data=data;
        head->next=NULL;
    }else{
        Node* temp = head;
        while(temp->next!=NULL)temp=temp->next;
        Node* n = (Node*) malloc(sizeof(Node));
        n->data=data;
        n->next=NULL;
        temp->next=n;
    }
    return head;
}
Node* addAtPosition(Node* head,int data, int position){
    if(position<0){
        printf("Position cannot be negative");
        return head;
    }
    if(position==0){
        Node* node=(Node*) malloc(sizeof(Node));
        node->data=data;
        node->next=head;
        head=node;
        return head;
    }else{
        Node* temp=head;
        while(position--!=1){
            temp=temp->next;
            if(temp==NULL){
                printf("position cannot be greater than size of list");
                return head;
            }
        }
        
        Node* node=(Node*) malloc(sizeof(Node));
        node->data=data;
        node->next=temp->next;
        temp->next=node;
    }
    return head;
}
Node* deletePosition(Node* head,int position){
    if(position==0){
        head=head->next;
        free(head);
        return head;
    }
    Node* temp=head;
    while(position--!=1)temp=temp->next;
    Node* del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return head;
}
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        //next=next->next;
    }
    return prev;
}
void printList(Node* head){
    Node* temp=head;
    printf("\n******* Printing List ********\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    Node* head=NULL;
    head=add(head,3);
    head=add(head,5);
    head=add(head,10);
    head=addAtPosition(head,12,3);
    head=deletePosition(head,0);
    head=reverse(head);
    printList(head);
    printf("%d",sizeof(int));
    return 0;
}
