#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void insert(AVL *t, int d){
    node *data = (node *)malloc(sizeof(node));
    data->data = d;
    data->l = data->r = data->p = NULL;
    data->bf = 0;

    node *p = *t;
    node *q = NULL;
    while(p){
        q = p;
        if(p->data > d)
            p = p->l;
        else
            p = p->r;
    }

    if(!q)
        (*t) = data;
    else if(q->data > d){
        q->l = data;
        data->p = q;
    }
    else{
        q->r = data;
        data->p = q;
    }

    adjustBF(data->p);
    node * imb = (node *)malloc(sizeof(node));
    imb = imbalanceNode(data->p);

    printf("Inserted %d\n", d);
    if(imb){
        printf("Imbalance node: %d\n" ,imb->data);
    }

    if(imb && imb->bf==2 && imb->l && imb->l->bf==1){
        leftRotate(t,imb);
    }
}

void leftRotate(AVL *t, node *imb){
    node *A = imb;
    node *B = imb->l;
    node *P = A->p;

    node *BR=B->r;

    B->r=A;
    A->l=BR;
    A->p=B;
    B->p=P;

    if(BR){
        BR->p=A;
    }


    if((*t)==A){
        (*t)=B;
    }

    // printf("\n%d\n",(*t)->data);
    // printf("\n%d\n",(*t)->l->data);
    // printf("\n%d\n",(*t)->r->data);

    // A->l=NULL;

    adjustBF(A);
}

void adjustBF(AVL t){
    if(!t)
        return;
    int lh = height(t->l);
    int rh = height(t->r);
    t->bf = lh - rh;

    adjustBF(t->p);
}

node *imbalanceNode(AVL t){
    if(!t)
        return NULL;
    if(t->bf > 1 || t->bf < -1)
        return t;
    return imbalanceNode(t->p);
}

int height(AVL t){
    if(!t)
        return 0;
    int lh = height(t->l);
    int rh = height(t->r);
    return (lh > rh ? lh : rh) + 1;
}

void inorder(AVL t){
    if(t){
        inorder(t->l);
        printf("%d -> %d\n", t->data, t->bf);
        inorder(t->r);
    }
}

void preorder(AVL t){
    if(t){
        printf("%d -> %d\n", t->data, t->bf);
        preorder(t->l);
        preorder(t->r);
    }
}