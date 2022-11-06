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
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void InOrder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void PostOrder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}