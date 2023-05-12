#include<stdio.h>
#include<stdlib.h>
#include "func.h"

void main(){
    heap *h = (heap*) malloc(sizeof(heap));
    init(h);

    // insert(h, 10);
    // printf("\nAfter Insert:");
    // display(h);
    
    // insert(h, 20);
    // printf("\nAfter Insert:");
    // display(h);

    // insert(h, 30);
    // printf("\nAfter Insert:");
    // display(h);

    // insert(h, 40);
    // printf("\nAfter Insert:");
    // display(h);

    // insert(h, 50);
    // printf("\nAfter Insert:");
    // display(h);

    // insert(h, 60);
    // printf("\nAfter Insert:");
    // display(h);

    // insert(h, 70);
    // printf("\nAfter Insert:");
    // display(h);

    insert(h, 12);
    printf("\nAfter Insert:");
    display(h);
    
    insert(h, 1);
    printf("\nAfter Insert:");
    display(h);

    insert(h, 13);
    printf("\nAfter Insert:");
    display(h);

    insert(h, 121);
    printf("\nAfter Insert:");
    display(h);

    insert(h, 98);
    printf("\nAfter Insert:");
    display(h);

    insert(h, 17);
    printf("\nAfter Insert:");
    display(h);

    insert(h, 15);
    printf("\nAfter Insert:");
    display(h);

    insert(h, 45);
    printf("\nAfter Insert:");
    display(h);

    insert(h, 3);
    printf("\nAfter Insert:");
    display(h);

    insert(h, 23);
    printf("\nAfter Insert:");
    display(h);

    // // printf("\nSize: %d",h->c);

    // delete(h);
    // printf("\nFinal: ");
    // display(h);

    // delete(h);
    // printf("\nFinal: ");
    // display(h);

    // delete(h);
    // printf("\nFinal: ");
    // display(h);

    

    // sortUsingHeap(h);
    // delete(h);
    // printf("\nFinal: ");
    // display(h);
    // delete(h);
    // printf("\nFinal: ");
    // display(h);
    // delete(h);
    // printf("\nFinal: ");
    // display(h);
    // delete(h);
    // printf("\nFinal: ");
    // display(h);
    // delete(h);
    // printf("\nFinal: ");
    // display(h);
    // delete(h);
    // printf("\nFinal: ");
    // display(h);
    // delete(h);
    // printf("\nFinal: ");
    // display(h);
    // delete(h);
    // printf("\nFinal: ");
    // display(h);

    // insert(h, 10);
    // printf("\nAfter Insert:");
    // display(h);

    delete(h);

    sortUsingHeap(h);

    printf("\nFinal: ");
    display(h);
}