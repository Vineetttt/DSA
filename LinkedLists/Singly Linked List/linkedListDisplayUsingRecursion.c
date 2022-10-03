#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
}*first = NULL;

void recDisplayLL(struct node * ptr){
    if(ptr != NULL){
        printf("%d ",ptr->data);
        recDisplayLL(ptr->next);
    }
}

void createLL(int A[] ,int n){
    int i;
    struct node *newNode,*last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next =NULL;
    last=first;
    for(i=1;i<n;i++){
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = A[i];
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

int main(){
    int A[] = {10,20,30,40,50};
    createLL(A,5);
    recDisplayLL(first);
}