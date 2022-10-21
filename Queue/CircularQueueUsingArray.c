#include <stdio.h>
#include <stdlib.h>
#define size 10

int queue[size];
int front=-1,rear=-1;

void enqueue(){
    int x;
    if((rear+1)%size == front){
        printf("Queue Overflow, cannot insert");
    }
    else{
        printf("Enter the element you want to insert: ");
        scanf("%d",&x);
        rear = (rear+1)%size;
        queue[rear] = x;
    }
}
int dequeue(){
    int x =-1;
    if(front == rear){
        printf("Queue underflow, connot delete");
        return x;
    }
    else{
        front = (front+1)%size;
        x = queue[front];
        return x;
    }
}
void display(){
    int i = front+1;
    do{
        printf("%d ",queue[i]);
        i = (i+1)%size;
    }while(i != (rear+1)%size);
}
int main(){
    int choice;
    do{
        printf("\nEnter:\n1.To perform enqueue operation\n2.To perform dequeue operation\n3.To Display\n4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                enqueue();
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