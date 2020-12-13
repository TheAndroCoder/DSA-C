/**
 * Program to create BST
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* root=NULL;

Node* newnode(int val){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=val;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void add(int val){
    if(root==NULL){
        root=newnode(val);
        return;
    }
    Node* curr=root;
    while(1){
        if(curr->data>val){
            if(curr->left==NULL){
                curr->left=newnode(val);
                return;
            }
            curr=curr->left;
        }else{
            if(curr->right==NULL){
                curr->right=newnode(val);
                return;
            }
            curr=curr->right;
        }
    }   
}
void inOrder(Node* p){
    if(p==NULL)return;
    inOrder(p->left);
    printf("%d ",p->data);
    inOrder(p->right);
}

int main(){
    int arr[]={20,10,30,21,34,56,3,9};
    int size=8;
    for(int i=0;i<size;i++){
        add(arr[i]);
    }
    inOrder(root);
    printf("\n");
    return 0;
}