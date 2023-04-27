#include<stdio.h>
#include<stdlib.h>
#include "func.c"

void main(){
    AVL t = NULL;
    // insert(&t, 20);
    // insert(&t, 10);
    // insert(&t, 5);
    // insert(&t, 2);

    insert(&t, 10);
    insert(&t, 5);
    insert(&t, 12);
    insert(&t, 9);
    insert(&t, 2);
    insert(&t, 1);

    preorder(t);
}
