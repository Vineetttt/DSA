#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

int precedence(char x){
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
}
int isOperator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
    else return 1;
}

char *infixTOpostfix(char *infix){
    int i=0,j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len+2)*sizeof(char));
    while(infix[i] != '\0'){
        if(isOperator(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(precedence(infix[i] > precedence(top->data)))
                Push(infix[i++]);
            else
                postfix[j++] = Pop();
        }
    }
    while(top != NULL)
        postfix[j++] = Pop();
    postfix[j] = '\0';
    return postfix;
}

void Push(char x){
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
    Push('#');
    char *infix;
    printf("Enter an infix expression: ");
    fgets(infix,100, stdin);
    char *postfix = infixTOpostfix(infix);
    printf("Postfix expression: \n%s",postfix);
}