/**
 * Program for Queue using Array
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX];
int front=-1,rear=-1;

// Queue ADT
void enqueue(int);
int dequeue();
int isEmpty();
int first();
int last();

int main(){
    
    return 0;
}

void enqueue(int value){
    if(rear==MAX-1){
        printf("Queue Full");
        return;
    }
    arr[++rear]=value;
}
int dequeue(){
    if(front==rear){
        printf("Queue Empty");
        return -999;
    }
    return arr[++front];
}

int isEmpty(){
    if(rear==-1 || front==rear)return 1;
    return 0;
}

int first(){
    if(!isEmpty())return arr[front+1];
    return -1;
}
int last(){
    if(!isEmpty())return arr[rear];
    return -1;
}