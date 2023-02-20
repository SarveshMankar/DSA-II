#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

void initBST(node **tree)
{
    tree = NULL;
}

void insertNode(node **t, int data){
	node *nn = (node*)malloc(sizeof(node));
	nn->data=data;
	if (*t==NULL){
		*t=nn;
	}else if(data<(*t)->data){
		insertNode(&(*t)->left,data);
	}else if(data>(*t)->data){
		insertNode(&(*t)->right,data);
	}
}

int search(node *t, int data){
	if (t==NULL){
		return 0;
	}
	if((t)->data==data){
		return 1;
	}else if(data<(t)->data){
		search(t->left,data);
	}else if(data>(t)->data){
		search(t->right,data);
	}
}

void displayLevel(node *t, int curr, int tl){
	if(t == NULL)
        return;
    if(curr == tl){
        printf("%d\t",t->data);
        return;
    }
    displayLevel(t->left, curr+1, tl);
    displayLevel(t->right, curr+1, tl);
}

int deptTree(node *t){
	if (t==NULL){
		return 0;
	}
	int left = deptTree(t->left);
	int right = deptTree(t->right);

	if (left>right){
		return left+1;
	}else{
		return right+1;
	}
}

void displayTree(node *t){
	int curr=0;
	int depth = deptTree(t) - 1;

	for(int i=0; i<=depth; i++){
		printf("\n");
		displayLevel(t,curr,i);
	}

}