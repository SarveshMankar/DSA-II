#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void init(heap *h){
    h->A=(int*)malloc(100*sizeof(int));
    h->s=100;
    h->c=-1;
}

void insert(heap *h, int data){
    if(h->c==-1){
        h->A=(int*)malloc(sizeof(int));
        if(!h){
            return;
        }
        h->c++;
        h->A[h->c]=data;
        return;
    }
    if(h->c<=h->s){
        h->A=realloc(h->A,(h->c+1)*sizeof(int));
        if(!h->A){
            return;
        }
        h->c++;
        h->A[h->c]=data;

    }

    heapify(h);
    // display(h);
    printf("\nAFter Insert:");
    display(h);
    
    return;
}

void delete(heap *h){
    int data = h->A[0];
    int flag=0;
    int i=0;
    for(i; i<h->c+1;i++){
        if(h->A[i]==data){
            flag=1;
            // printf("OP!");
            break;
        }
    }

    if(flag){
        // printf("\n%d %d",h->A[i], h->A[h->c]);
        swap(&h->A[i],&h->A[h->c]);
        // printf("\n%d %d",h->A[i], h->A[h->c]);
        h->c--;
    
        // printf("\nDeleting:");
        // display(h);

        heapifydel(h);
    }
    return;
}

void heapify(heap *h){
    int i=h->c;
    while(i>0 && h->A[i]>h->A[(i-1)/2]){
        // printf("\nHeapify: %d %d",h->A[i],h->A[(i-1)/2]);
        swap(&h->A[i],&h->A[(i-1)/2]);
        i=(i-1)/2;
    }
}

void heapifydel(heap *h){
    int i=0;
    int c=0;
    while (i<h->c)
    {
        c++;
        // if(2*i+1>h->c-1){
        //     break;
        // }
        if(h->A[i]<h->A[2*i+1] && h->A[i]<h->A[2*i+2]){
            if(h->A[2*i+1]>h->A[2*i+2]){
                swap(&h->A[i],&h->A[2*i+1]);
                i=2*i+1;
            }
            else{
                swap(&h->A[i],&h->A[2*i+2]);
                i=2*i+2;
            }
        }
        else if(h->A[i]<h->A[2*i+1]){
            swap(&h->A[i],&h->A[2*i+1]);
            i=2*i+1;
        }
        else if(h->A[i]<h->A[2*i+2]){
            swap(&h->A[i],&h->A[2*i+2]);
            i=2*i+2;
        }
        else{
            break;
        }
        if(2*i+1>h->c-1){
            break;
        }
    }
    
}

void display(heap *h){
    for(int i=0;i<=h->c;i++){
        printf("%d ",h->A[i]);
    }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}