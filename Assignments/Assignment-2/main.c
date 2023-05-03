#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"func.h"


int main(){
    aBST t;
    initBST(&t);

    insertBST(&t, 10);
    insertBST(&t, 5);
    insertBST(&t, 15);
    insertBST(&t, 3);
    insertBST(&t, 7);
    insertBST(&t, 12);
    insertBST(&t, 17);
    insertBST(&t, 15);
    insertBST(&t, 32);
    insertBST(&t, 2);
    insertBST(&t, 1);
    insertBST(&t, 8);
    insertBST(&t, 9);

    printf("Inorder: ");
    inOrder(&t);
    printf("\n");

    printf("\nHeight: %d",height(&t));

    printf("\nLeaf Nodes: %d",countLeafNodes(&t));

    printf("\nComplete: %d",isComplete(&t));

    printf("\nLevel Order: \n");
    levelOrder(&t);

    return 0;
}