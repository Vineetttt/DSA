#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void Push(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL) printf("Stack Overflow");
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop(){
    int x = -1;
    struct Node *t;
    if(top == NULL) printf("Stack Underflow");
    else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *p;
     p = top;
     while(p != NULL){
        printf("%d\n",p->data);
        p = p->next;
     }
}

int main(){
    int choice,x,data;
    do{
        printf("Enter:\n1.To Push and element\n2.To Pop an element\n3.To Display\n4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                Push(data);
                break;
            case 2: 
                Pop();
                break;
            case 3: 
                Display();
                break;
            default: printf("\nInvalid choice!!");
        }
    }while(choice != 4);
}