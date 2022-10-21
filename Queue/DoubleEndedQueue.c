#include <stdio.h>
#include <stdlib.h>
#define size 10

int queue[size];
int front=-1,rear=-1;

void enQueueRear(){
     int x;
     if(front == size/2){
            printf("\nQueue is full!!! Insertion is not possible!!! ");
            return;
      }
      else{
            printf("\nEnter the value to be inserted:");
            scanf("%d",&x);
            queue[front] = x;
            front++;
      }
}
void enQueueFront(){ 
     int x;  
     if(front==size/2){
            printf("\nQueue is full!!! Insertion is not possible!!!");
            return;
      }
      else{
            printf("\nEnter the value to be inserted:");
            scanf("%d",&x);
            rear--;
            queue[rear] = x;
      }
}
int deQueueRear(){
     int deleted;
     if(front == rear){
            printf("\nQueue is Empty!!! Deletion is not possible!!!");
            return 0;
     }
     front--;
     deleted = queue[front+1];
     return deleted;
}
int deQueueFront(){
     int deleted;
     if(front == rear){
            printf("\nQueue is Empty!!! Deletion is not possible!!!");
            return 0;
     }
     rear++;
     deleted = queue[rear-1];
     return deleted;
}
void display(){
     int i;
     if(front == rear)
        printf("\nQueue is Empty");
     else{
        printf("\nThe Queue elements are:");
        for(i=rear; i < front; i++){
           printf("%d ",queue[i]);
        }
     }
}
int main(){
    int choice;
    do{
        printf("\nEnter:\n1.To perform enqueue from REAR operation\n2.To perform enqueue from FRONT operation\n"
        "3.To perform dequeue from REAR operation\n4.To perform dequeue from FRONT operation\n5.To perform display operation\n6.Exit");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                enQueueRear();
                break;
            case 2: 
                enQueueFront();
                break;
            case 3: 
                deQueueRear();
                break;
            case 4: 
                deQueueFront();
                break;
            case 5: 
                display();
                break;
        }
    }while(choice != 6);
}