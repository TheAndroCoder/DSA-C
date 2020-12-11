#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* head=NULL;
int size=0;

// functions prototype

void add(int);
void addAtPos(int,int);
void deletePos(int);
void reverse();
void print();

int main(){
    add(10);
    add(15);
    addAtPos(13,2);
    reverse();
    print();
    return 0;
}

void add(int value){
    if(head==NULL){
        // linkedlist is empty
        head=(Node*) malloc(sizeof(Node));
        head->data=value;
        head->next=head;
        head->prev=head;
    }else{
        Node* temp=head->prev;
        Node* new_node=(Node*) malloc(sizeof(Node));
        new_node->data=value;
        new_node->next=head;
        temp->next=new_node;
        head->prev=new_node;
        new_node->prev=temp;
    }
    size++;
}

void addAtPos(int value,int pos){
    if(pos<=0 || pos>size+1){
        printf("Invalid position value\n");
        return;
    }
    if(pos==1){
        // insert at head
        add(value);
        size--;
        head=head->prev;

    }else if(pos==size+1){
        //insert at tail
        add(value);
        size--;
    }else{
        Node* temp=head;
        Node* new_node=(Node*) malloc(sizeof(Node));
        new_node->data=value;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next->prev=new_node;
        temp->next=new_node;
    }
    size++;
}

void deletePos(int pos){
    if(pos<=0 || pos>size){
        printf("Invalid position value\n");
        return;
    }
    if(pos==1){
        Node* temp=head->prev;
        temp->next=head->next;
        head->next->prev=temp;
        free(head);
        head=temp->next;
    }else{
        Node* temp=head;
        for(int i=1;i<pos-1;i++)temp=temp->next;
        temp->next=temp->next->next;
        temp->next->prev=temp;
        free(temp->next);
    }
    size--;
}

void reverse(){
    if(head==NULL)return;
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    do{
        prev=curr->prev;
        next=curr->next;

        curr->next=prev;
        curr->prev=next;
        curr=curr->prev;
    }while(curr!=head);
    head=curr->next;
}

void print(){
    if(head==NULL)return;
    Node* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\nList size = %d\n",size);
}