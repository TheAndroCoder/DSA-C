/**
 * Program for Queue using Singly LinkedList
 * @author TheAndroCoder
 * */
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front=NULL;
Node* rear=NULL;

// function prototypes
void enqueue(int);
int dequeue();
int isEmpty();
void print();

int main(){
    enqueue(10);
    enqueue(20);
    dequeue();
    dequeue();
    dequeue();
    print();
    return 0;
}

int isEmpty(){
    if(front==NULL)return 1;
    return 0;
}
void enqueue(int value){
    if(isEmpty()){
        Node* new_node=(Node*) malloc(sizeof(Node));
        new_node->data=value;
        new_node->next=NULL;
        front=new_node;
        rear=new_node;
    }else{
        Node* new_node=(Node*)malloc(sizeof(Node));
        new_node->data=value;
        new_node->next=NULL;
        rear->next=new_node;
        rear=new_node;
    }
}
int dequeue(){
    if(isEmpty()){
        printf("Queue is Empty");
        return -1;
    }
    Node* temp=front;
    int x=front->data;
    front=front->next;
    free(temp);
    return x;
}
void print(){
    Node* temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

