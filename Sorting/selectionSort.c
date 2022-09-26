#include <stdio.h>

void selectionSort(int a[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(a[j] < a[k]){
                k=j;
            }
        }
        swap(&a[i],&a[k]);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int n ;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    selectionSort(A,n);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}