/**
 * Creation of Max Heap (in-place)(using arrays)
 * @author TheAndroCoder
 * */

#include<stdio.h>

int heapsize=1;

/**
 * Insert New Element into heap
 * @param a : max-heap array
 * @param n : newly inserted element index
 * */
void insert(int a[],int n){
    int temp,i=n;
    temp=a[n];
    while(i>1 && temp>a[i/2]){
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
    heapsize++;
}
void print(int a[]){
    for(int i=1;i<=heapsize;i++)printf("%d ",a[i]);
    printf("\n");
}
int main(){
    int a[]={0,10,20,30,25,5,40,35};
    // a[0] is ignored and not used, indexes start from 1 onwards
    // 30 is root element
    
    for(int i=2;i<8;i++){
        // one by one each element is heapified
        insert(a,i);
    }

    print(a);
    return 0;
}