#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
}*first = NULL;

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


void displayLL(struct node * ptr){
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    int A[] = {10,20,30,40,50};
    createLL(A,5);
    displayLL(first);
}