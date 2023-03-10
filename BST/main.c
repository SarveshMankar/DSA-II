#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;


typedef node* BST;

void initBST(BST *t);
void insertWithRecursion(BST *t, int key);
void insertWithoutRecursion(BST *t, int key);

void inOrderWithRecursion(BST t);
void push(int arr[], int *top, int data);

void preOrderWithRecursion(BST t);

void postOrderWithRecursion(BST t);

int countNodesWithRecursion(BST t);

int countLeafNodesWithRecursion(BST t);

int countInternalNodesWithRecursion(BST t);




void initBST(BST *t){
    // node *temp = (node*)malloc(sizeof(node));
    // temp->left = NULL;
    // temp->right = NULL;

    // *t = temp;
    *t = NULL;
}

void insertWithRecursion(BST *t, int key){
    if((*t)==NULL){
        node *nn = (node *)malloc(sizeof(node));
        nn->data=key;
        nn->left=nn->right=NULL;
        *t=nn;
    }else if((*t)->data==key){
        return;
    }else if((*t)->data>key){
        insertWithRecursion(&(*t)->left,key);
    }else if((*t)->data<key){
        insertWithRecursion(&(*t)->right,key);
    }
}

void insertWithoutRecursion(BST *t, int key){
    node *nn = (node *) malloc(sizeof(node));
    nn->data=key;
    nn->right=nn->left=NULL;

    node *p = *t;
    node *q = NULL;

    while (p!=NULL){
        q=p;

        if(p->data==key){
            return;
        }

        if(p->data>key){
            p=p->left;
        }else if (p->data<key){
            p=p->right;
        }        
    }

    if (q->data>key){
        q->left=nn;
    }else{
        q->right=nn;
    }
}

void preOrderWithRecursion(BST t){
    if(t!=NULL){
		printf("%d\t",t->data);
		preOrderWithRecursion(t->left);
		preOrderWithRecursion(t->right);	
	}
}

void inOrderWithRecursion(BST t){
    if(t!=NULL){
		inOrderWithRecursion(t->left);
		printf("%d\t",t->data);
		inOrderWithRecursion(t->right);	
	}
}

void postOrderWithRecursion(BST t){
    if(t!=NULL){
		postOrderWithRecursion(t->left);
		postOrderWithRecursion(t->right);	
		printf("%d\t",t->data);
	}
}

int countNodesWithRecursion(BST t){
    if(t==NULL){
        return 0;
    }
    return 1+countNodesWithRecursion(t->left)+countNodesWithRecursion(t->right);
}

int countLeafNodesWithRecursion(BST t){
    if(t==NULL){
        return 0;
    }
    if(t->left==NULL && t->right==NULL){
        return 1;
    }
    return countLeafNodesWithRecursion(t->left)+countLeafNodesWithRecursion(t->right);
}

int countInternalNodesWithRecursion(BST t){
    if (t==NULL || (t->left==NULL && t->right==NULL)){
        return 0;
    }
    // if (t==NULL)
    // {
    //     return 0;
    // }
    // if((t->left==NULL && t->right!=NULL) || (t->right==NULL && t->left!=NULL)){
    //     return 1;
    // }
    

    return 1+countInternalNodesWithRecursion(t->left)+countInternalNodesWithRecursion(t->right);
}



int main(){
    BST t = NULL;
    initBST(&t);

    insertWithRecursion(&t, 10);
    insertWithRecursion(&t, 5);
    insertWithRecursion(&t, 15);
    insertWithRecursion(&t, 3);
    insertWithRecursion(&t, 7);
    insertWithRecursion(&t, 12);
    insertWithRecursion(&t, 17);
    insertWithRecursion(&t, 15);

    insertWithoutRecursion(&t, 32);
    insertWithoutRecursion(&t, 1);
    insertWithoutRecursion(&t, 8);
    insertWithoutRecursion(&t, 65);
    insertWithoutRecursion(&t, 23);
    insertWithoutRecursion(&t, 4);



    printf("PreOrder Traversal with Recursion:\n");
    preOrderWithRecursion(t);
    printf("\n");

    printf("InOrder Traversal with Recursion:\n");
    inOrderWithRecursion(t);
    printf("\n");

    printf("PostOrder Traversal with Recursion:\n");
    postOrderWithRecursion(t);
    printf("\n");

    int cn = countNodesWithRecursion(t);
    printf("\nCounting Number of Nodes with Recursion:%d\n",cn);

    int cl = countLeafNodesWithRecursion(t);
    printf("\nCounting Leaf Nodes with Recursion:%d\n",cl);

    int ci = countInternalNodesWithRecursion(t);
    printf("\nCounting Internal Nodes with Recursion:%d\n",ci);

    return 0;
}