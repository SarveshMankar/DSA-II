#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;


typedef node* BST;

typedef struct stack{
    node *data;
    struct stack *next;
}stack;

stack* top = NULL;

// void initStack(stack **s);
void push(node *data);
node *pop();

void initBST(BST *t);
void insertWithRecursion(BST *t, int key);
void insertWithoutRecursion(BST *t, int key);

void inOrderWithRecursion(BST t);
void inOrderWithoutRecursion(BST t);

void preOrderWithRecursion(BST t);

void postOrderWithRecursion(BST t);

int countNodesWithRecursion(BST t);
int countNodesWithoutRecursion(BST t);

int countLeafNodesWithRecursion(BST t);

int countInternalNodesWithRecursion(BST t);

int isFullTree(BST t);

int height(BST t);

void push(node *data){
    stack *s = (stack *)malloc(sizeof(stack));
    s->data=data;
    if(top==NULL){
        s->next=NULL;
    }else{
        s->next=top;
    }
    top=s;
    // printf("\n%d",top->data->data);
}

node *pop(){
    if(top==NULL){
        printf("UnderFlow!");
    }else{
        stack *temp = top;
        top=top->next;
        return temp->data;
        // stack *p=top;
        // stack *tn=p->next;
        // top=p->next;
        // free(p);
        // return tn->data;
    }
}

void initBST(BST *t){
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

void inOrderWithoutRecursion(BST t){
    node *p=t;
    printf("\n");

    if(p==NULL){
        return;
    }
    while (1)
    {
        if(p){
            push(p);
            p=p->left;
        }else{
            if(top){
                p=pop();
                printf("%d\t",p->data);
                p=p->right;
                // break;
            }else{
                break;
            }
        }
    }  

    return;
    
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

int countNodesWithoutRecursion(BST t){

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
    return 1+countInternalNodesWithRecursion(t->left)+countInternalNodesWithRecursion(t->right);
}

int isFullTree(BST t){
    if(!t){
        return 1;
    }
    if(t->left == NULL && t->right==NULL){
        return 1;
    }
    if(t->left != NULL && t->right!=NULL){
        return isFullTree(t->left) && isFullTree(t->right);
    }
    return 0;
}

int height(BST t){
    if(!t){
        return 0;
    }else{
        int l=height(t->left);
        int r=height(t->right);

        if(l>r){
            return l+1;
        }else{
            return r+1;
        }
    }
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
    // insertWithoutRecursion(&t, 8);
    insertWithoutRecursion(&t, 65);
    insertWithoutRecursion(&t, 23);
    insertWithoutRecursion(&t, 4);

    // insertWithRecursion(&t, 25);
    // insertWithRecursion(&t, 20);
    // insertWithRecursion(&t, 36);
    // insertWithRecursion(&t, 10);
    // insertWithRecursion(&t, 22);
    // insertWithRecursion(&t, 30);
    // insertWithRecursion(&t, 40);


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

    int isFull = isFullTree(t);
    printf("\nIs Tree Full: %d",isFull);

    int h = height(t);
    printf("\nHeight of Tree: %d",h);
    printf("\n");

    printf("\nInOrder Traversal without Recursion:\n");
    inOrderWithoutRecursion(t);
    printf("\n");

    printf("\nWorking Well!\n");

    return 0;
}