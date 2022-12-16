//Functions for different Tree Traversals

struct Node
{
 struct Node *lchild;
 int data;
 struct Node *rchild;
};

void PreOrder(struct Node *p){
    if(p){
        printf("%d",p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void InOrder(struct Node *p){
    if(p){
        InOrder(p->lchild);
        printf("%d ",p->data);
        InOrder(p->rchild);
    }
}

void PostOrder(struct Node *p){
    if(p){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%d ",p->data);
    }
}