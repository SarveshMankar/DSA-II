#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"


void initStack(stack *s){
    s->top=NULL;
}

void push(stack *s, node *data){
    stack *t = (stack *)malloc(sizeof(stack));
    t->data=data;
    if(s->top==NULL){
        s->next=NULL;
    }else{
        t->next=s->top;
    }
    s->top=t;
    // printf("\n%d",top->data->data);
}

node *pop(stack *s){
    if(s->top==NULL){
        printf("UnderFlow!");
    }else{
        stack *temp = s->top;
        s->top=s->top->next;
        return temp->data;
        // stack *p=top;
        // stack *tn=p->next;
        // top=p->next;
        // free(p);
        // return tn->data;
    }
}

stack *destroyStack(stack *s){
    stack *temp=s;
    stack *t;
    while (temp->top){
        t=temp->top->top;
        free(temp->top);
        temp=t;
    }
    free(temp);

    return NULL;    
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

void preOrderWithoutRecursion(BST t){    
    node *p=t;

    stack *preOrderStack = (stack *)malloc(sizeof(stack));
    initStack(preOrderStack); 

    if(p==NULL){
        return;
    }
    while (1)
    {
        if(p){
            push(preOrderStack,p);
            printf("%d\t",p->data);
            p=p->left;
        }else{
            if(preOrderStack->top){
                p=pop(preOrderStack);
                p=p->right;
                // break;
            }else{
                break;
            }
        }
    }  

    preOrderStack=destroyStack(preOrderStack);
    free(preOrderStack);

    return;
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

    if(p==NULL){
        return;
    }

    stack *inOrderStack = (stack *)malloc(sizeof(stack));
    initStack(inOrderStack); 

    while (1)
    {
        if(p){
            push(inOrderStack,p);
            p=p->left;
        }else{
            if(inOrderStack->top){
                p=pop(inOrderStack);
                printf("%d\t",p->data);
                p=p->right;
            }else{
                break;
            }
        }
    }  

    inOrderStack=destroyStack(inOrderStack);
    free(inOrderStack);

    return;
}

void postOrderWithRecursion(BST t){
    if(t!=NULL){
		postOrderWithRecursion(t->left);
		postOrderWithRecursion(t->right);	
		printf("%d\t",t->data);
	}
}

void postOrderWithoutRecursion(BST t){
    node *p=t;

    if(p==NULL){
        return;
    }

    stack *postOrderStack = (stack *)malloc(sizeof(stack));
    initStack(postOrderStack); 

    while (1)
    {
        if(p){
            if(p->right){
                push(postOrderStack,p->right);
            }
            push(postOrderStack,p);
            p=p->left;
        }else{
            if(postOrderStack->top){
                // printf("%d\t",p->data);
                p=pop(postOrderStack);
                if(!p->right){
                    printf("%d\t",p->data);
                    p=NULL;
                }
                if(!p){
                    p=pop(postOrderStack);
                    if(p->data==postOrderStack->top->data->data){
                        printf("%d\t",postOrderStack->top->data->data);
                        push(postOrderStack,p);
                    }
                }
                // p=p->right;
                // break;
            }else{
                break;
            }
        }
    }

    postOrderStack=destroyStack(postOrderStack);
    free(postOrderStack);

    return;
}

int countNodesWithRecursion(BST t){
    if(t==NULL){
        return 0;
    }
    return 1+countNodesWithRecursion(t->left)+countNodesWithRecursion(t->right);
}

int countNodesWithoutRecursion(BST t){
    node *p=t;
    int count=0;

    if(p==NULL){
        return count;
    }

    stack *countNodesStack = (stack *)malloc(sizeof(stack));
    initStack(countNodesStack); 

    while (1)
    {
        if(p){
            push(countNodesStack,p);
            p=p->left;
        }else{
            if(countNodesStack->top){
                p=pop(countNodesStack);
                count++;
                // printf("%d\t",p->data);
                p=p->right;
            }else{
                break;
            }
        }
    }

    countNodesStack=destroyStack(countNodesStack);
    free(countNodesStack);

    return count;
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

int countLeafNodesWithoutRecursion(BST t){
    node *p=t;
    int count=0;

    if(p==NULL){
        return count;
    }

    stack *countLeafNodesStack = (stack *)malloc(sizeof(stack));
    initStack(countLeafNodesStack); 

    while (1)
    {
        if(p){
            push(countLeafNodesStack,p);
            p=p->left;
        }else{
            if(countLeafNodesStack->top){
                p=pop(countLeafNodesStack);
                if(p->left==NULL && p->right==NULL){
                    count++;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }

    countLeafNodesStack=destroyStack(countLeafNodesStack);
    free(countLeafNodesStack);

    return count;
}


int countInternalNodesWithRecursion(BST t){
    if (t==NULL || (t->left==NULL && t->right==NULL)){
        return 0;
    }
    return 1+countInternalNodesWithRecursion(t->left)+countInternalNodesWithRecursion(t->right);
}

int countInternalNodesWithoutRecursion(BST t){
    node *p=t;
    int count=0;

    if(p==NULL){
        return count;
    }

    stack *countInternalNodesStack = (stack *)malloc(sizeof(stack));
    initStack(countInternalNodesStack); 

    while (1)
    {
        if(p){
            push(countInternalNodesStack,p);
            p=p->left;
        }else{
            if(countInternalNodesStack->top){
                p=pop(countInternalNodesStack);
                if(p->left==NULL){
                    if(p->right){
                        count++;
                    }
                }else{
                    count++;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }

    countInternalNodesStack=destroyStack(countInternalNodesStack);
    free(countInternalNodesStack);

    return count;
}

int isFullTreeWithRecursion(BST t){
    if(!t){
        return 1;
    }
    if(t->left == NULL && t->right==NULL){
        return 1;
    }
    if(t->left != NULL && t->right!=NULL){
        return isFullTreeWithRecursion(t->left) && isFullTreeWithRecursion(t->right);
    }
    return 0;
}

int isFullTreeWithoutRecursion(BST t){
    node *p=t;
    if(!p){
        return 1;
    }

    stack *isFullStack = (stack *)malloc(sizeof(stack));
    initStack(isFullStack);

    while (1){
        if(p){
            push(isFullStack,p);
            p=p->left;
        }else{
            if (isFullStack->top){
                p=pop(isFullStack);
                if ((p->left && !p->right) || (!p->left && p->right)){
                    return 0;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }

    isFullStack=destroyStack(isFullStack);
    free(isFullStack);

    return 1;
}

int isCompleteTreeWithoutRecursion(BST t){
    node *p=t;
    int flag=0;
    if(!p){
        return 1;
    }

    stack *isCompleteStack = (stack *)malloc(sizeof(stack));
    initStack(isCompleteStack); 

    while (1){
        if(p){
            push(isCompleteStack,p);
            p=p->left;
        }else{
            if(isCompleteStack->top){
                p=pop(isCompleteStack);
                if(!p->left && p->right){
                    if (flag==1){
                        return 0;
                    }
                    flag=1;
                    // return 0;
                }
                p=p->right;
            }else{
                break;
            }
        }
    }
    
}

void insertBT(BST *t, int key){
	if ( (*t) == NULL){
		BST n = (BST) malloc(sizeof(node));
		n->data = key;
		n->left = n->right = NULL;
		*t = n;
	}

	if(rand() % 2 == 0){
		if(!(*t)->left){
			BST n = (BST) malloc(sizeof(node));
			n->data = key;
			n->left = n->right = NULL;
			(*t)->left = n;
			return;
		}

		insertBT(&(*t)->left, key);
	}
	else {
		if(!(*t)->right){
			BST n = (BST) malloc(sizeof(node));
			n->data = key;
			n->left = n->right = NULL;
			(*t)->right = n;
			return;
		}
		insertBT(&(*t)->right, key);
	}
	return;
}

int isBST(BST t){
    node *p=t;
    node *q;

    if(p==NULL){
        return 1;
    }

    stack *isBSTStack = (stack *)malloc(sizeof(stack));
    initStack(isBSTStack); 

    while (1)
    {
        if(p){
            push(isBSTStack,p);
            p=p->left;
            if(isBSTStack->top && p){
                if(p->data>isBSTStack->top->data->data){
                    return 0;
                }
            }
        }else{
            if(isBSTStack->top){
                p=pop(isBSTStack);
                // printf("%d\t",p->data);
                q=p;

                p=p->right;
                if(q && p){
                    if(p->data<q->data){
                        return 0;
                    }
                }
            }else{
                break;
            }
        }
    }  

    isBSTStack=destroyStack(isBSTStack);
    free(isBSTStack);

    return 1;
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

// void farLeafNode(BST t){
//     int t1=0;
//     int t2=0;
//     int c=0;
//     treenode *p=t;

//     stack st;
//     initStack(&st);

//     while(1){
//         if(p){
//             push(&st, p);
//             p=p->left;
//             t1++;
//             printf("\nt1=%d\tt2=%d",t1,t2);

//         }
//         else{
//             if(!isStackEmpty(st)){
//                 p=pop(&st);
//                 if(!p->left && !p->right){
//                     if(t1>t2){
//                         // printf("\nt1=%d\tt2=%d",t1,t2);
//                         t2=t1;
//                         c=p->data;
//                     }
//                     printf("\t%d",p->data);
//                     t1--;
//                 }
//                 p=p->right;
//                 printf("\nt1=%d\tt2=%d",t1,t2);
//             }else{
//                 break;
//             }
//         }
//     }
//     printf("\n%d",c); 
// }

void destroyWithRecursion(BST *t){
    if(*t){
        destroyWithRecursion(&(*t)->left);
        destroyWithRecursion(&(*t)->right);
        free(*t);
        *t=NULL;
    }
}

node *destroyWithoutRecursion(BST t){
    if(!t){return NULL;}
    node *p=t;
    node *q;

    stack *destroyTreeStack = (stack *)malloc(sizeof(stack));
    initStack(destroyTreeStack); 
    
    while (1){
        if(p){
            push(destroyTreeStack,p);
            p=p->left;
        }else{
            if(destroyTreeStack->top){
                p=pop(destroyTreeStack);
                q=p->right;
                // printf("%d\t",p->data);
                free(p);
                p=q;
            }else{
                break;
            }
        }
    }

    destroyTreeStack=destroyStack(destroyTreeStack);
    free(destroyTreeStack);

    free(q);
    return NULL;
    
}

int dc=0;
int countLevelNodes(node *t, int curr, int tl){
	if(t == NULL){
        // printf("\nAns:%d\n",dc);
        return dc;
    }
    if(curr == tl){
        dc++;
        // printf("%d=%d\t",t->data,dc);
    }
    countLevelNodes(t->left, curr+1, tl);
    countLevelNodes(t->right, curr+1, tl);
}

int breadthRecusrion(BST t){
    int breadth=0;
    int temp;
    for(int i=0;i<height(t);i++){
        dc=0;
        temp=countLevelNodes(t,0,i);
        if(temp>breadth){
            breadth=temp;
        }
    }
    return breadth;
}