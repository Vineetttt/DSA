#include <stdio.h>

int len=10,top =-1,stack[10];

void Push(){
    int data;
    if(top == len-1) printf("Stack Overflow");
    else{
        printf("\nEnter element to be inserted: ");
		scanf("%d",&data);
		top=top+1;
		stack[top]=data;
    }
}

void Pop(){
    if(top == -1) printf("Stack Underflow");
    else{
        printf("\nPopped element:  %d\n",stack[top]);
		top=top-1;
    }
}

int Peek() {
   return stack[top];
}

void Display(){
    if(top == -1) printf("Stack Underflow");
    else{
        printf("\nElements present in the stack: \n");
		for(int i=top;i>=0;--i)
			printf("%d\n",stack[i]);
    }
}

int main(){
    int choice,x;
    do{
        printf("Enter:\n1.To Push and element\n2.To Pop an element\n3.To Peek\n4.To Display\n5.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                Push();
                break;
            case 2: 
                Pop();
                break;
            case 3: 
                x = Peek();
                printf("Top most element in the stack is: \n%d",x);
                break;
            case 4: 
                Display();
                break;
            default: printf("\nInvalid choice!!");
        }
    }while(choice != 5);
}