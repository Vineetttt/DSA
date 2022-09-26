#include <stdio.h>

void bubbleSort(int A[] ,int n){
    int i,j,flag=0;
    for(i=0;i<n;i++){
        flag = 0;
        for(j=0;j<n-i-1;j++){
            if(A[j] > A[j+1]){
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
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
    bubbleSort(A,n);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}