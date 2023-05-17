#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void init(heap *h){
    h->A=NULL;
    h->s=100;
    h->c=-1;
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



void maxheap_insert(heap *h, int data){
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

    maxheap_heapify(h);
    
    return;
}

void maxheap_heapify(heap *h){
    int i=h->c;
    while(i>0 && h->A[i]>h->A[(i-1)/2]){
        swap(&h->A[i],&h->A[(i-1)/2]);
        i=(i-1)/2;
    }
}

void maxheap_delete(heap *h){
    if(h->c<=0){
        h->c=-1;
        return;
    }

    int data = h->A[0];

    swap(&h->A[0],&h->A[h->c]);
    h->c--;
    maxheap_heapifydel(h);

    return;
}

void maxheap_heapifydel(heap *h){
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

void maxheap_ascendingSortUsingHeap(heap *h){
    int nodes=h->c+1;
    int index=h->c;

    for(int j=0; j<nodes; j++){
        int data = h->A[0];
        int i=0;
        
        swap(&h->A[i],&h->A[index]);
        index--;

        maxheap_heapifysort(h, index);
    }

    if(h->A[0] > h->A[1])
        swap(&h->A[0], &h->A[1]);
    return;
}

void maxheap_heapifysort(heap *h, int index){
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


void minheap_insert(heap *h, int data){
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

    minheap_heapify(h);
    
    return;
}

void minheap_heapify(heap *h){
    int i=h->c;
    while(i>0 && h->A[i]<h->A[(i-1)/2]){
        swap(&h->A[i],&h->A[(i-1)/2]);
        i=(i-1)/2;
    }
}


void minheap_delete(heap *h){
    if(h->c<=0){
        h->c=-1;
        return;
    }

    int data = h->A[0];

    swap(&h->A[0],&h->A[h->c]);
    h->c--;
    minheap_heapifydel(h);

    return;
}

void minheap_heapifydel(heap *h){
    int i=0;
    int imin=0;
    while (i<h->c)
    {
        if(2*i+1>h->c-1){
            break;
        }
        if(h->A[2*i+1]<h->A[2*i+2]){
            imin=2*i+1;
        }else{
            imin=2*i+2;
        }

        if(h->A[i]>h->A[imin]){
            swap(&h->A[i],&h->A[imin]);
            i=imin;
        }else{
            break;
        }
    }
}

void minheap_descendingSortUsingHeap(heap *h){
    int nodes=h->c+1;
    int index=h->c;

    for(int j=0; j<nodes; j++){
        int data = h->A[0];
        int i=0;
        
        swap(&h->A[i],&h->A[index]);
        index--;

        minheap_heapifysort(h, index);
    }

    if(h->A[0] < h->A[1])
        swap(&h->A[0], &h->A[1]);
    return;
}

void minheap_heapifysort(heap *h, int index){
    int i=0;
    int imin=0;
    while (i<index+1){
        if(2*i+1>index-1){
            break;
        }
        if(h->A[2*i+1]<h->A[2*i+2]){
            imin=2*i+1;
        }else{
            imin=2*i+2;
        }

        if(h->A[i]>h->A[imin]){
            swap(&h->A[i],&h->A[imin]);
            i=imin;
        }else{
            break;
        }
    }
}