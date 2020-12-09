#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* head=NULL;
int size=0;

// Append to list
void add(int value){
    if(head==NULL){
        head=(Node*)malloc(sizeof(Node));
        head->data=value;
        head->next=head;
        size++;
        return;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    Node* new_node = (Node*) malloc(sizeof(Node));
    temp->next=new_node;
    new_node->next=head;
    new_node->data=value;
    size++;
}
void addAtPos(int value,int pos){
    if(pos<=0 || pos>size+1)return;
    if(pos==1){
        Node* temp=head;
        while(temp->next!=head)temp=temp->next;
        Node* new_node =(Node*) malloc(sizeof(Node));
        new_node->data=value;
        new_node->next=head;
        temp->next=new_node;
        head=new_node;
        
    }else{
        
        Node* temp=head;
        for(int i=1;i<pos-1;i++)temp=temp->next;

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data=value;
        new_node->next=temp->next;
        temp->next=new_node;
    }
    size++;
}

void printList(){
    printf("******Printing Circular LinkedList*****\n");
    Node* temp=head;
    int i=0;
    do{
        printf("%d ",temp->data);
        i++;
        temp=temp->next;
        if(i==30)break;
    }while(temp!=head);
    
    printf("\n");
}

void deletePos(int pos){
    if(pos<=0 || pos>size){
        printf("Invalid Position value, Size of list is %d\n",size);
        return;
    }
    Node *temp=head;
    if(pos==1){
        // navigate to last node then remove last->next
        while(temp->next!=head)temp=temp->next;
        temp->next=head->next;
        head=head->next;
        free(temp->next);
    }else{
        for(int i=1;i<pos-1;i++)temp=temp->next;
        temp->next=temp->next->next;
        free(temp->next);
    }
    size--;
}

void reverse(){
    if(head==NULL)return;
    Node* prev=NULL;Node* curr=head;Node* next;
    do{
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }while(curr!=head);
    head->next=prev;
    head=prev;
}

Node* findMiddle(){
    if(head==NULL)return NULL;
    Node* slow=head;
    Node* fast=head;
    while(1){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==head)break;
        if(fast->next==head)break;
    }
    return slow;
}

int main(){
    add(2);
    add(3);
    add(4);
    add(5);
    //add(4);
    //reverse();
    printList();
    printf("List size=%d\n",size);

    // find middle
    Node* middle=findMiddle();
    printf("Middle Element: %d\n",middle->data);
    return 0;
}