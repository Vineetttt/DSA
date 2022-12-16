#include <stdio.h>
#include <stdlib.h>

// here the time taken to create an entire Heap is O(nlogn)
void InsertHeap(int a[], int n){
    int temp, i =n;
    temp = a[i];
    while(i>1 && temp > a[i/2]){
        a[i] = a[i/2];
        i=i/2;
    }
    a[i]=temp;
}
int Delete(int a[], int n){
    int i,j,x,val,temp;
    val = a[1];
    x=a[n];
    a[1]=a[n];
    a[n]=val;
    i=1;j=i*2;
    while(j<n-1){
        if(a[j+1] > a[j])
            j+=1;
        if(a[i]<a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i=j;
            j=2*j;
        }
    }
    return val;
}
int main(){
    int H[] = {0,10,20,30,25,5,40,35};
    for(int i=2;i<=7;i++){
        InsertHeap(H,i);
    }
    printf("Deleted element: %d\n",Delete(H,7));
    //Deleted element is stored at last
    for(int i=1;i<=7;i++){
        printf("%d ",H[i]);
    }
}