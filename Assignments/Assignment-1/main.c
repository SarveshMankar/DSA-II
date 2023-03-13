#include<stdio.h>
#include<stdlib.h>
#include"func.h"

int main(){
    BT t1 = NULL; //BST
    FILE *fptr1;
    fptr1 = fopen("data.txt", "r");
    
    initBT(&t1);
    int num1;
    for(int i=0;i<10;i++){
        fscanf(fptr1, "%d", &num1);
        insertBST(&t1, num1);
    }

    inorder(t1);

    fclose(fptr1);

    printf("\n-----------------\n");


    BT t2 = NULL; //BT
    FILE *fptr2;
    fptr2 = fopen("data.txt", "r");
    
    initBT(&t1);
    int num2;
    for(int i=0;i<10;i++){
        fscanf(fptr2, "%d", &num2);
        insertBT(&t1, num2);
    }

    inorder(t1);

    fclose(fptr2);

    int count=0;
    count=searchBST(t1, 47794, count);
    printf("Comparison=%d",count);

}