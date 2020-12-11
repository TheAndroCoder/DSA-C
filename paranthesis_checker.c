#include<stdio.h>
#include<stdlib.h>

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
int main(){
    char* exp="((a+b)*(c+d))\0";
    int i=0;
    int balanced=1;
    while(1){
        char curr=*(exp+i);
        if(curr=='(')
        push(curr);
        else if(curr==')'){
            if(!isEmpty())pop();
            else {
                balanced=0;
                break;
            }
        }
        i++;
        if(curr=='\0')break;
    }
    if(isEmpty() && balanced)printf("Balanced Paranthesis\n");
    else printf("Unbalanced\n");
    return 0;
}