/**
 * Faster method of creating heaps (Heapify)
 * @author TheAndroCoder
 * */

#include<stdio.h>
int heapsize=8;

void heapify(int a[],int n){
    // if no children then return
    if(2*n>heapsize)return;

    if(2*n<heapsize && 2*n+1>=heapsize){
        // only left child exists
        if(a[2*n]>a[n]){
            int temp=a[2*n];
            a[2*n]=a[n];
            a[n]=temp;
            heapify(a,2*n);
        }
    }else if(2*n<heapsize && 2*n+1<heapsize){
        // both child exists
        if(a[2*n]>a[2*n+1] && a[2*n]>a[n]){
            int temp=a[2*n];
            a[2*n]=a[n];
            a[n]=temp;
            heapify(a,2*n);
        }else if(a[2*n+1]>a[2*n] && a[2*n+1]>a[n]){
            int temp=a[2*n+1];
            a[2*n+1]=a[n];
            a[n]=temp;
            heapify(a,2*n+1);
        }
    }
}
void print(int a[]){
    for(int i=1;i<8;i++)printf("%d ",a[i]);
    printf("\n");
}

int main(){
    int a[]={0,10,20,30,25,5,40,35};
    for(int i=7;i>=1;i--){
        heapify(a,i);
    }

    print(a);
    // expected output : 40 25 35 20 5 30 10
    return 0;
}