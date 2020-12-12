/**
 * Program to create a Binary Tree (using queue) + Tree Traversals
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* root=NULL;

Node* arr[MAX];
int front=-1;
int rear=-1;

// queue utility functions
void enqueue(Node* pointer){
    if(rear==MAX-1){
        printf("Queue full");
        return;
    }
    arr[++rear]=pointer;
}
int isEmpty(){
    if(front==rear)return 1;
    return 0;
}
Node* dequeue(){
    if(isEmpty()){
        printf("Empty Queue");
        return NULL;
    }
    return arr[++front];
}

// Utility functions for Binary Tree creation
Node* add(Node* p,int value,char pos){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    if(pos=='l'){
        p->left=new_node;
    }else if(pos=='r'){
        p->right=new_node;
    }
    return new_node;
}
void InOrder(Node* p){
    if(p->left!=NULL)InOrder(p->left);
    printf("%d ",p->data);
    if(p->right!=NULL)InOrder(p->right);
}
void PreOrder(Node* p){
    printf("%d ",p->data);
    if(p->left!=NULL)PreOrder(p->left);
    if(p->right!=NULL)PreOrder(p->right);
}
void PostOrder(Node* p){
    if(p->left!=NULL)PostOrder(p->left);
    if(p->right!=NULL)PostOrder(p->right);
    printf("%d ",p->data);
}
int main(){
    printf("Enter the root Node Value\n");
    int value=0;
    scanf("%d",&value);
    root=(Node*) malloc(sizeof(Node));
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    enqueue(root);
    while(!isEmpty()){
        Node* p=dequeue();
        printf("Enter Left child value for node : %d (-1 for no child)\n",p->data);
        int data = 0;
        scanf("%d",&data);
        if(data!=-1){
            Node* added_node=add(p,data,'l');
            enqueue(added_node);
        }
        printf("Enter Right child value for node : %d (-1 for no child)\n",p->data);
        scanf("%d",&data);
        if(data!=-1){
            Node* added_node=add(p,data,'r');
            enqueue(added_node);
        }
    }
    printf("\nPreOrder Traversal\n");
    PreOrder(root);
    printf("\nInOrder Traversal\n");
    InOrder(root);
    printf("\nPostOrder Traversal\n");
    PostOrder(root);
    printf("\n");
}
