#include <stdio.h>

void insertionSort(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp = a[i];
        j=i-1;
        while((j >= 0) && (temp < a[j])){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
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
    insertionSort(A,n);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}