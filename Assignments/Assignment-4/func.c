#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void init(heap *h){
    h->A=NULL;
    h->s=100;
    h->c=-1;
}

void insert(heap *h, int data){
    if(h->c==-1){
        h->A=realloc(h->A,(h->c+2)*sizeof(int));
    }else{
        h->A=realloc(h->A,(h->c+2)*sizeof(int));
    }

    if(!h->A){
        return;
    }
    h->c++;
    h->A[h->c]=data;

    heapify(h);
    
    return;
}

void delete(heap *h){
    if(h->c<=0){
        h->c=-1;
        return;
    }

    int data = h->A[0];

    swap(&h->A[0],&h->A[h->c]);
    h->c--;
    heapifydel(h);

    return;
}

void heapify(heap *h){
    int i=h->c;
    while(i>0 && h->A[i]>h->A[(i-1)/2]){
        swap(&h->A[i],&h->A[(i-1)/2]);
        i=(i-1)/2;
    }
}

void heapifydel(heap *h){
    int i=0;
    int imax=0;
    while (i<h->c)
    {
        if(2*i+1>h->c-1){
            break;
        }
        if(h->A[2*i+1]>h->A[2*i+2]){
            imax=2*i+1;
        }else{
            imax=2*i+2;
        }

        if(h->A[i]<h->A[imax]){
            swap(&h->A[i],&h->A[imax]);
            i=imax;
        }else{
            break;
        }
    }
}

void sortUsingHeap(heap *h){
    int nodes=h->c+1;
    int index=h->c;

    int maxlimit=0;
    if((index+1)%2==0){
        maxlimit=0;
    }else{
        maxlimit=1;
    }

    for(int j=0; j<nodes; j++){
        int data = h->A[0];
        int i=0;
        
        swap(&h->A[i],&h->A[index]);
        index--;

        heapifysort(h, index);
        if(index==maxlimit){
            break;
        }
    }

    // if(h->A[0] > h->A[1])
    //     swap(&h->A[0], &h->A[1]);
    return;
}

void heapifysort(heap *h, int index){
    int i=0;
    int imax=0;
    while (i<index+1){
        if(2*i+1>index-1){
            break;
        }
        if(h->A[2*i+1]>h->A[2*i+2]){
            imax=2*i+1;
        }else{
            imax=2*i+2;
        }

        if(h->A[i]<h->A[imax]){
            swap(&h->A[i],&h->A[imax]);
            i=imax;
        }else{
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