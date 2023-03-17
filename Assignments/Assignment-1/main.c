#include<stdio.h>
#include<stdlib.h>
#include"func.h"

int main(){
    BT t1 = NULL; //BST
    FILE *fptr1;
    fptr1 = fopen("data-10k.txt", "r");
    
    initBT(&t1);
    int num1;
    for(int i=0;i<10000;i++){
        fscanf(fptr1, "%d", &num1);
        insertBST(&t1, num1);
    }

    // inorder(t1);

    fclose(fptr1);

    printf("\n-----------------\n");


    BT t2 = NULL; //BT
    FILE *fptr2;
    fptr2 = fopen("data-10k.txt", "r");
    
    initBT(&t2);
    int num2;
    for(int i=0;i<10000;i++){
        fscanf(fptr2, "%d", &num2);
        insertBT(&t2, num2);
    }
    
    printf("\n-----------------\n");
    // inorder(t2);

    fclose(fptr2);

    int count1=0;
    int count2=0;
    FILE *fptr3;
    fptr3 = fopen("data-compare.txt", "r");
    int num3;
    for(int i=0;i<100;i++){
        fscanf(fptr3, "%d", &num3);
        count1=0;
        count1=searchBST(t1, num3, count1);
        printf("\n%d Comparison in Binary Search Tree=%d",num3,count1);

        count2=0;
        count2=searchBT(t2, num3, count2);
        printf("\n%d Comparison in Binary Tree=%d",num3,count2);
        // searchBST(t1, num1, 0);
        // searchBT(t2, num1, 0);
    }
    printf("\n-----------------\n");
    fclose(fptr3);


    // count=0;
    // count=searchBT(t1, 30887, count);
    // printf("\nComparison in BT=%d",count);
}