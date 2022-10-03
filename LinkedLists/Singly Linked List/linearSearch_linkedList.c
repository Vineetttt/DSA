#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct node * linearSearch(struct node *p,int key){
    struct node *counter;
    while(p!=NULL){
        if(key==p->data){
            counter->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        counter=p;
        p=p->next;
    }
 return NULL;
}

int main(){
    int A[] = {1,-20,34,65,-23,87,100,0};
    createLL(A,8);
    struct node *temp;
    temp = linearSearch(first,-23);
    if(temp){
        printf("Element found at memory location: %p",first);
    }
    else{
        printf("Element not found");
    }
}