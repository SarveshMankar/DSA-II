#include<stdio.h>
#include<stdlib.h>
#include "func.h"

int main(){
    heap *h = (heap*) malloc(sizeof(heap));
    init(h);

    // int type;
    // printf("\n1. Max Heap\n2. Min Heap\n");
    // scanf("%d",&type);

    // if (type==1){
    //     int t=1;
    //     while(t){
    //         printf("\n1. Insert\n2. Delete\n3. Display\n4. Sort in Ascending Order\n5. Sort in Descending Order \n6. Exit\n");
    //         int ch;
    //         scanf("%d",&ch);

    //         switch (ch){
    //         case 1:
    //             printf("\nEnter data: ");
    //             int data;
    //             scanf("%d",&data);
    //             maxheap_insert(h, data);
    //             printf("\nAfter Insert:");
    //             display(h);
    //             break;
    //         case 2:
    //             maxheap_delete(h);
    //             printf("\nAfter Delete: ");
    //             display(h);
    //             break;
    //         case 3:
    //             printf("\nDisplay: ");
    //             display(h);
    //             break;
    //         case 4:
    //             maxheap_sortUsingHeap(h);
    //             printf("\nAfter Sorting in Ascending Order: ");
    //             display(h);
    //             break;
    //         case 5:
    //             maxheap_sortUsingHeap(h);
    //             printf("\nAfter Sorting in Descending Order: ");
    //             break;
    //         case 6:
    //             t=0;
    //             break;
    //         default:
    //             break;
    //         }
    //     }
    // }else if (type==2){
    //     int t=1;
    //     while(t){
    //         printf("\n1. Insert\n2. Delete\n3. Display\n4. Sort in Ascending Order\n5. Sort in Descending Order \n6. Exit\n");
    //         int ch;
    //         scanf("%d",&ch);

    //         switch (ch){
    //         case 1:
    //             printf("\nEnter data: ");
    //             int data;
    //             scanf("%d",&data);
    //             maxheap_insert(h, data);
    //             printf("\nAfter Insert:");
    //             display(h);
    //             break;
    //         case 2:
    //             maxheap_delete(h);
    //             printf("\nAfter Delete: ");
    //             display(h);
    //             break;
    //         case 3:
    //             printf("\nDisplay: ");
    //             display(h);
    //             break;
    //         case 4:
    //             maxheap_sortUsingHeap(h);
    //             printf("\nAfter Sorting in Ascending Order: ");
    //             display(h);
    //             printf("Ok");
    //             break;
    //         case 5:
    //             maxheap_sortUsingHeap(h);
    //             printf("\nAfter Sorting in Descending Order: ");
    //             display(h);
    //             break;
    //         case 6:
    //             t=0;
    //             break;
    //         default:
    //             break;
    //         }
    //     }
    // }else{
    //     printf("\nInvalid Choice\n");
    // } 

    minheap_insert(h, 12);
    printf("\nAfter Insert:");
    display(h);
    
    minheap_insert(h, 1);
    printf("\nAfter Insert:");
    display(h);

    minheap_insert(h, 13);
    printf("\nAfter Insert:");
    display(h);

    minheap_insert(h, 121);
    printf("\nAfter Insert:");
    display(h);

    minheap_insert(h, 98);
    printf("\nAfter Insert:");
    display(h);

    minheap_insert(h, 17);
    printf("\nAfter Insert:");
    display(h);

    minheap_insert(h, 15);
    printf("\nAfter Insert:");
    display(h);

    minheap_insert(h, 45);
    printf("\nAfter Insert:");
    display(h);

    minheap_insert(h, 3);
    printf("\nAfter Insert:");
    display(h);

    minheap_insert(h, 23);
    printf("\nAfter Insert:");
    display(h);

    minheap_delete(h);
    printf("\nAfter Delete: ");
    display(h);

    minheap_descendingSortUsingHeap(h);

    printf("\nFinal: ");
    display(h);

    return 0;
    
}