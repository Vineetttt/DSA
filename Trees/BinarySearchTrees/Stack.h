//creating a header file for basic Stack Operations used while working with trees

struct Stack{
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *st,int size){
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size*sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x){
    if(st->top == st->size-1){
        printf("Stack Overflow");
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st){
    struct Node *x = NULL;
    if(st->top == -1){
        printf("Stack Overflow");
    }
    else{
        x = st->S[st->top--];
    }
    return x;
}
struct Node *peek(struct Stack *st){
    int x = st->top;
    /*printf("%d is the top most element of the stack\n", x);*/
    //return x;
}
int isStackEmpty(struct Stack st){
    if(st.top == -1){
        return 1;
    }
    return 0;
}

int isStackFull(struct Stack st){
    return st.top == st.size-1;
}
