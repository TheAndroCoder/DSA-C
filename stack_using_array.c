#include<stdio.h>
#include<stdbool.h>
#define MAX 3
int size=0;
int top=-1;
int arr[MAX];

// function prototype
void printList();
void push(int);
int pop();
int peek();
bool isEmpty();

int main(){
    push(10);
    pop();
    pop();
    printList();
    return 0;
}

void push(int value){
    if(top==MAX-1){
        printf("Stack Full");
        return;
    }
    arr[++top]=value;
    size++;
}
int pop(){
    if(top==-1){
        printf("No Elements in list");
        return -1;
    }
    size--;
    return arr[top--];
}
int peek(){
    if(top==-1){
        printf("Empty Stack");
        return -1;
    }
    return arr[top];
}
bool isEmpty(){
    if(top==-1)return true;
    return false;
}
void printList(){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}