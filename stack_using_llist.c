#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int size=0;
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head=NULL;

// function prototype
void push(int);
int pop();
int peek();
bool isEmpty();

int main(){
    push(100);
    push(200);
    push(300);
    printf("%d\n",pop());
    return 0;
}

void push(int value){
    if(head==NULL){
        head=(Node*) malloc(sizeof(Node));
        head->data=value;
        head->next=NULL;
    }else{
        Node* new_node=(Node*)malloc(sizeof(Node));
        new_node->data=value;
        new_node->next=head;
        head=new_node;
    }
    size++;
}

int pop(){
    if(!head)return -1;
    int x = head->data;
    Node* temp=head;
    head=head->next;
    free(temp);
    size--;
    return x;
}
int peek(){
    if(!head)return -1;
    return head->data;
}
bool isEmpty(){
    return head==NULL;
}