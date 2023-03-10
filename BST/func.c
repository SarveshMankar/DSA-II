#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"

void initBST(BST *t){
    node *temp = (node*)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;

    *t = temp;
}

