#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"

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

    // insertBT(&t, 10);
    // insertBT(&t, 5);
    // insertBT(&t, 15);
    // insertBT(&t, 3);
    // insertBT(&t, 7);
    // insertBT(&t, 12);


    printf("PreOrder Traversal with Recursion:\n");
    preOrderWithRecursion(t);
    printf("\n");

    printf("InOrder Traversal with Recursion:\n");
    inOrderWithRecursion(t);
    printf("\n");

    printf("PostOrder Traversal with Recursion:\n");
    postOrderWithRecursion(t);
    printf("\n");

    int cnr = countNodesWithRecursion(t);
    printf("\nCounting Number of Nodes with Recursion:%d\n",cnr);

    int cni = countNodesWithoutRecursion(t);
    printf("Counting Number of Nodes without Recursion:%d\n",cni);

    int clr = countLeafNodesWithRecursion(t);
    printf("\nCounting Leaf Nodes with Recursion:%d\n",clr);

    int cli = countLeafNodesWithoutRecursion(t);
    printf("Counting Leaf Nodes without Recursion:%d\n",cli);

    int ci = countInternalNodesWithRecursion(t);
    printf("\nCounting Internal Nodes with Recursion:%d\n",ci);

    int cr = countInternalNodesWithoutRecursion(t);
    printf("Counting Internal Nodes without Recursion:%d\n",cr);

    int isFullr = isFullTreeWithRecursion(t);
    printf("\nIs Tree Full with Recursion: %d",isFullr);

    int isFulli = isFullTreeWithoutRecursion(t);
    printf("\nIs Tree Full without Recursion: %d",isFulli);

    int isCompletei = isCompleteTreeWithoutRecursion(t);
    printf("\n\nIs Tree Complete without Recursion: %d\n",isCompletei);

    int isBSTi = isBST(t);
    printf("\nIs Tree BST without Recursion: %d\n",isBSTi);

    int h = height(t);
    printf("\nHeight of Tree: %d",h);
    printf("\n");

    printf("\nPreOrder Traversal without Recursion:\n");
    preOrderWithoutRecursion(t);
    printf("\n");

    printf("\nInOrder Traversal without Recursion:\n");
    inOrderWithoutRecursion(t);
    printf("\n");

    // printf("\nPostOrder Traversal without Recursion:\n");
    // postOrderWithoutRecursion(t);
    // printf("\n");
    
    int breadth=breadthRecusrion(t);
    printf("\nBreadth of Tree:%d\n",breadth);

    // printf("\nDestroying Tree:\n");
    // destroyWithRecursion(&t);

    printf("\nDestroying Tree!\n");
    t=destroyWithoutRecursion(t);

    printf("\nWorking Well!\n");

    return 0;
}