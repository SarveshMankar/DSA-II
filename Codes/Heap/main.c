#include<stdio.h>
#include<stdlib.h>
#include "func.c"

void main(){
    heap *h = (heap*) malloc(sizeof(heap));
    init(h);

    insert(h, 10);
    insert(h, 20);
    insert(h, 30);
    insert(h, 40);
    insert(h, 50);
    insert(h, 60);
    // insert(h, 70);

    // // printf("\nSize: %d",h->c);

    delete(h);
    printf("\nFinal: ");
    display(h);

    delete(h);
    printf("\nFinal: ");
    display(h);

    delete(h);
    printf("\nFinal: ");
    display(h);

    // display(h);
}