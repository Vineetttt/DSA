#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
}*front = NULL,*rear=NULL;

void enqueue(int x){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    // if the heap is full 
    if(t == NULL)
        printf("Queue Overflow");
    else{
        t->data = x;
        t->next = NULL;
        // if it is the first node
        if(front == NULL){
            front = rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue(){
    int x = -1;
    struct node *t;
    if(front == NULL)
        printf("Queue underflow");
    else{
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
int isEmpty()
{
 return front==NULL; 
}