#include <stdio.h>
#include <stdlib.h>

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
void display(){
    struct node *p=front;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    int choice,x;
    do{
        printf("\nEnter:\n1.To perform enqueue operation\n2.To perform dequeue operation\n3.To Display\n4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                printf("Enter an element to insert: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2: 
                dequeue();
                break;
            case 3: 
                display();
                break;
        }
    }while(choice != 4);
}