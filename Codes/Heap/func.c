#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void init(heap *h){
    h->A=(int*)malloc(100*sizeof(int));
    h->s=100;
    h->c=0;
}

void insert(heap *h, int data){
    if(h->c==0){
        h->A=(int*)malloc(sizeof(int));
        if(!h){
            return;
        }
        h->A[0]=data;
        h->c++;
        return;
    }
    if(h->c<=h->s){
        h->A=realloc(h->A,(h->c+1)*sizeof(int));
        if(!h->A){
            return;
        }
        h->A[h->c]=data;
        h->c++;

    }

    heapify(h);
    // display(h);
    
    return;
}

void heapify(heap *h){
    int i=h->c-1;
    // printf("\ni=%d",i);
    while(i>0 && h->A[i]>h->A[(i-1)/2]){
        swap(&h->A[i],&h->A[(i-1)/2]);
        i=(i-1)/2;
        // printf("\nswapped");
    }
}

void display(heap *h){
    for(int i=0;i<h->c;i++){
        printf("\n%d ",h->A[i]);
    }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}