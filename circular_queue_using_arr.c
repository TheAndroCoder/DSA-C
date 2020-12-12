/**
 * Program for Circular Queue using array and two pointers
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int front=-1,rear=-1;
int arr[MAX];

// function prototypes
void enqueue(int);
int dequeue();
int first();
int last();
int isEmpty();
int isFull();
void print();

int main(){
    enqueue(10);
    enqueue(30);
    dequeue();
    dequeue();
    dequeue();
    print();
    return 0;
}

int isFull(){
    if((rear==MAX-1 && front==-1) || (rear==front-1))return 1;
    return 0;
}
int isEmpty(){
    if(rear==-1 || front==rear)return 1;
    return 0;
}
void enqueue(int value){
    if(isFull()){
        printf("Queue is Full");
        return;
    }
    rear++;
    arr[rear%MAX]=value;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is Empty");
        return -1;
    }
    front++;
    return arr[front%MAX];
}
int last(){
    if(!isEmpty())return arr[rear];
    return -1;
}
int first(){
    if(!isEmpty())return arr[front];
    return -1;
}
void print(){
    for(int i=0;i<MAX;i++)printf("%d ",arr[i]);
}