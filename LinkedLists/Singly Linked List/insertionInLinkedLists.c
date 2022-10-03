#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL;

void insert(struct node * p,int index , int value){
    int i;
    int len = countNodes(first);
    //if user input index is invalid break the fucntion 
    if(index < 0 || index > len)
    return;

    struct node * insertNode;
    insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->data = value;
    //if the index is 0 then insert it on extreme left; happens in O(1)
    if(index == 0){
        //the address points to the previous first element
        insertNode->next = first; 
        first = insertNode;
    }
    //if the index value is other than 0
    //minimum time taken when index=1 i.e. O(1) and maximum time taken is number of nodes O(n)
    else{
        // move the pointer index-1 times for insertion
        for(i=0;i<index-1;i++){
            p = p->next;
        }
        insertNode->next = p->next;
        p->next = insertNode;
    }
}

int countNodes(struct node *p){
    int count = 0;
    while(p){
        count++;
        p= p->next;
    }
    return count;
}

void createLL(int A[],int n){
    struct node *newNode,*last;
    first =  (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++){
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data =A[i];
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
    int A[] = {20,30,50};
    createLL(A,3);
    printf("Original Linked List: ");
    displayLL(first);
    insert(first,0,10);
    insert(first,3,40);
    printf("\n  Linked List after insertions: ");
    displayLL(first);
}