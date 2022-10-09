#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
    else return 1;
}
int eval(char *postfix){
    int i=0,x1,x2,result;
    for(i=0;postfix[i] != '\0';i++){
        if(isOperand(postfix[i])){
// (-0) is extra as entered data is in string type conversion using ascii
            Push(postfix[i]-'0'); 
        }
        else{
            x2 = Pop();
            x1 = Pop();
            switch(postfix[i]){
                case '+':
                    result=x1+x2;
                    break;
                case '-':
                    result=x1-x2;
                    break;
                case '*':
                    result=x1*x2;
                    break;
                case '/':
                    result=x1/x2;
                    break;
            }
            Push(result);
        }
    }
    return top->data;
}

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

int main(){
    char *postfix = "231*+9-";
    printf("Evaluation of Postfix expression results:%d",eval(postfix));
}