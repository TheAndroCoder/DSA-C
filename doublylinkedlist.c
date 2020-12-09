#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* head=NULL;
int size=0;

// function prototypes
void add(int);
void printList();
void addAtPos(int,int);
void deletePos(int);
void reverse();

int main(){
    add(10);
    add(15);
    add(20);
    deletePos(3);
    reverse();
    printList();
    return 0;
}

// Append to end of list
void add(int value){
    if(head==NULL){
        head=(Node*) malloc(sizeof(Node));
        head->data=value;
        head->prev=NULL;
        head->next=NULL;
    }else{
        Node* temp=head;
        while(temp->next!=NULL)temp=temp->next;

        Node* new_node=(Node*)malloc(sizeof(Node));
        new_node->data=value;
        new_node->next=NULL;
        new_node->prev=temp;
        temp->next=new_node;
    }
    size++;
}

// Add at particular position (pos==1->head)
void addAtPos(int value,int position){
    if(position<=0 || position>size+1){
        printf("Invalid position value\n");
        return;
    }
    if(position==1){
        // add to head
        Node* new_node=(Node*) malloc(sizeof(Node));
        new_node->data=value;
        new_node->next=head;
        head->prev=new_node;
        new_node->prev=NULL;
        head=new_node;
    }else if(position==size+1){
        add(value);
    }else{
        Node* temp=head;
        Node* new_node=(Node*) malloc(sizeof(Node));
        for(int i=1;i<position-1;i++)temp=temp->next;
        new_node->data=value;
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next->prev=new_node;
    }
    size++;
}

void deletePos(int pos){
    if(pos<=0 || pos>size){
        printf("Invalid pos value\n");
        return;
    }
    if(pos==1){
        //remove head
        head=head->next;
        free(head);
    }else if(pos==size){
        Node* temp=head;
        for(int i=1;i<pos-1;i++)temp=temp->next;
        temp->next=NULL;
        free(temp->next);
    }else{
        Node* temp=head;
        for(int i=1;i<pos;i++)temp=temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    size--;
}

void reverse(){
    Node* curr=head;
    Node* temp=NULL;

    while(curr!=NULL){
        temp=curr->next;
        curr->next=curr->prev;
        curr->prev=temp;
        curr=curr->prev;
        if(curr!=NULL && curr->next==NULL)head=curr;
    }
}

void printList(){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}