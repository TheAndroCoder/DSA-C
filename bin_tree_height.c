/**
 * Program to create Binary Tree from Array and calculate its height and node count
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* root=NULL;

Node* arr[MAX];
int front=-1,rear=-1;

void push(Node* node){
    if(rear==MAX-1){
        printf("Queue Full");
        return;
    }
    arr[++rear]=node;
}
int isEmpty(){
    return front==rear;
}
Node* pop(){
    if(isEmpty()){
        printf("Queue Empty");
        return NULL;
    }
    return arr[++front];
}

Node* newnode(int value){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void makeTree(int a[],int n){
    root=(Node*)malloc(sizeof(Node));
    root->data=a[0];
    root->left=NULL;
    root->right=NULL;
    push(root);
    int i=1;
    while(!isEmpty() && i<n){
        Node* node=pop();
        if(node->left==NULL && i<n){
            node->left=newnode(a[i++]);
            push(node->left);
        }
        if(node->right==NULL && i<n){
            node->right=newnode(a[i++]);
            push(node->right);
        }
    }

}
void traverse(Node* p){
    if(p==NULL)return;
    traverse(p->left);
    printf("%d ",p->data);
    traverse(p->right);
}

int count(Node* p){
    if(p==NULL)return 0;
    int x=count(p->left);
    int y=count(p->right);
    return 1+x+y;
}
int height(Node* p){
    if(p==NULL)return 0;
    int lheight=height(p->left);
    int rheight=height(p->right);
    if(lheight>rheight)return 1+lheight;
    return 1+rheight;
}
int leafCount(Node* p){
    if(p==NULL)return 0;
    if(p->left==NULL && p->right==NULL)return 1;
    return leafCount(p->left)+leafCount(p->right);
}

int main(){
    int a[]={3,4,5,6,7,8,9};
    makeTree(a,7);
    traverse(root);
    printf("\nNode Count : %d\n",count(root));
    printf("Height : %d\n",height(root));
    printf("Leaf Nodes Count : %d\n",leafCount(root));
    return 0;
}