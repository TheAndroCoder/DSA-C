/**
 * Program for converting infix to postfix expression using stack (linkedlist implementation)
 * Also Postfix Expression Evaluation.
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

char* convert_to_postfix(char* exp){
    int i=0;
    int j=0;
    char* postfix=(char*)malloc(20*sizeof(char));
    while(exp[i]!='\0'){
        char c = exp[i];
        if(isOperand(c)){
            postfix[j++]=c;
        }else{
            if(isEmpty()){
                push(c);
            }else{
                if(pre(c)<=pre(peek())){
                    while(!isEmpty() && pre(c)<=pre(peek())){
                        postfix[j++]=pop();
                    }
                    push(c);
                }else{
                    push(c);
                }
            }
        }
        i++;
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

void evaluate_postfix(char* postfix){
    int i=0;
    while(postfix[i]!='\0'){
        char c=postfix[i];
        if(isOperand(c)){
            push(c);
        }else{
            int y=pop()-'0';
            int x=pop()-'0';
            if(c=='+'){
                int z=x+y;
                push(z+'0');
            }else if(c=='-'){
                int z=x-y;
                push(z+'0');
            }else if(c=='*'){
                int z=x*y;
                push(z+'0');
            }else{
                int z=x/y;
                push(z+'0');
            }
        }
        i++;
    }
    printf("POSTFIX EVALUATION : %d\n",(pop()-'0'));
}

int main(){
    char* exp="2+3*2-4/2\0";
    char* postfix=convert_to_postfix(exp);
    printf("POSTFIX : %s\n",postfix);
    evaluate_postfix(postfix);
    return 0;
}
