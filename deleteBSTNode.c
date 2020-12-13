/**
 * Program to delete a node from a BST
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

Node* inorder_predecessor(Node* p){
    while(p->right!=NULL){
        p=p->right;
    }
    return p;
}

Node* delete(Node* p,int val){
    if(p==NULL)return NULL;
    if(val<p->data){
        p->left=delete(p->left,val);
    }else if(val>p->data){
        p->right=delete(p->right,val);
    }else{
        if(p->left==NULL){
            // left child is null
            Node* temp=p->right;
            free(p);
            return temp;
        }else if(p->right==NULL){
            // right child is null
            Node* temp=p->left;
            free(p);
            return temp;
        }
        // both left and right child are not null
        Node* temp=inorder_predecessor(p->left);
        p->data=temp->data;
        p->left=delete(p->left,p->data);
    }
    return p;
}

void traverse(Node* p){
    if(p==NULL)return;
    traverse(p->left);
    printf("%d ",p->data);
    traverse(p->right);
}

int main(){
    int arr[]={20,10,30,21,34,56,3,9};
    int size=8;
    for(int i=0;i<size;i++){
        add(arr[i]);
    }
    //deleting the root
    root=delete(root,20);
    traverse(root);
    return 0;
}