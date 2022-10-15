#include <stdio.h>
#include <stdlib.h>
#define size 10

int queue[size];
int front=-1,rear=-1;

void enqueue(){
    int x;
    printf("Enter the element you want to insert: ");
    scanf("%d",&x);
    if(rear == size-1){
        printf("Queue Overflow, cannot insert");
    }
    else{
        rear++;
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
        x = queue[front];
        front++;
        return x;
    }
}
void display(){
        for(int i=front+1;i<=rear;i++){
            printf("%d  ",queue[i]);
        }
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