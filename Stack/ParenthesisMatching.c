// to check is the number of opening brackets '('is equal to the number of closing brackets ')' using stack
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

int isBalanced(char *str){
    int i;
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='(')
        Push(str[i]);
        else if(str[i]==')'){
            if(top==NULL)
            return 0;
            Pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
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
    char str[100];
    printf("Enter a code: ");
    fgets(str,100, stdin);
    int ans = isBalanced(str);
    if(ans == 1) printf("Equal Number of opening and closing parenthesis");
    else printf("Not a match, check the opening and closing again :(");
}