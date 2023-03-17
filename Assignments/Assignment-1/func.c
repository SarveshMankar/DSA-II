#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void initBT(BT *t){
    t=NULL;
}

void insertBST(BT *t, int key){
    if(*t==NULL){
        *t=(node *)malloc(sizeof(node));
        (*t)->data=key;
        (*t)->left=NULL;
        (*t)->right=NULL;
    }
    else{
        if(key<(*t)->data){
            insertBST(&(*t)->left, key);
        }
        else if(key>(*t)->data){
            insertBST(&(*t)->right, key);
        }
    }
}

int searchBST(BT t, int key, int count){
    if(t==NULL){
        return count;
    }
    if(t->data==key){
        return ++count;
    }
    if(t->data>key){
        searchBST(t->left,key,++count);
    }else if(t->data<key){
        searchBST(t->right,key,++count);
    }

}



void insertBT(BT *t, int key){
    if(*t==NULL){
        *t=(node *)malloc(sizeof(node));
        (*t)->data=key;
        (*t)->left=NULL;
        (*t)->right=NULL;
    }
    else{
        if(rand()%2!=0){
            insertBT(&(*t)->left, key);
        }
        else{
            insertBT(&(*t)->right, key);
        }
    }
}

int searchBT(BT t, int key, int count){
    if(t==NULL){
        return count;
    }
    
    searchBST(t->left,key,++count);
    if(t->data==key){
        return ++count;
    }
    searchBST(t->right,key,++count);
}

void inorder(BT t){
    if(t!=NULL){
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}