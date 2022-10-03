#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
}*first = NULL;

int countNodes(struct node *p){
    int count = 0;
    while(p){
        count++;
        p= p->next;
    }
    return count;
}