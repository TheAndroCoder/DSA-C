/**
 * Program for converting infix to postfix expression using stack (linkedlist implementation)
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>


// stack helper
typedef struct Node{
    char data;
    struct Node* next;
}Node;
Node* head=NULL;

void push(char value){
    if(head==NULL){
        head=(Node*)malloc(sizeof(Node));
        head->data=value;
        head->next=NULL;
    }else{
        Node* new_node = (Node*)malloc(sizeof(Node));
        Node* temp=head;
        new_node->data=value;
        new_node->next=head;
        head=new_node;
    }
}
char pop(){
    if(head==NULL)return '\0';
    char x=head->data;
    Node* temp=head;
    head=head->next;
    free(temp);
    return x;
}
int isEmpty(){
    if(head==NULL)return 1;
    return 0;
}
char peek(){
    if(head!=NULL)return head->data;
    return '\0';
}

// helper functions for infix to postfix conversion
int isOperand(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')return 0;
    return 1;
}
int pre(char c){
    if(c=='+' || c=='-')return 1;
    if(c=='*' || c=='/')return 2;
    return 0;
}

int main(){
    char* exp="a+b*c-d/e\0";
    int i=0;
    while(exp[i]!='\0'){
        char c = exp[i];
        if(isOperand(c)){
            printf("%c",c);
        }else{
            if(isEmpty()){
                push(c);
            }else{
                if(pre(c)>pre(peek())){
                    push(c);
                }else{
                    printf("%c",pop());
                }
            }
        }
        i++;
    }
    while(!isEmpty()){
        printf("%c",pop());
    }
    printf("\n");
    return 0;
}