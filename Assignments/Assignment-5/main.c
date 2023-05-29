#include<stdio.h>
#include<stdlib.h>
#include"func.h"
#include"queue.h"

int main(){
    graph G;
    initGraph(&G, "graph.txt");
    display(G);

    // Queue Q;
    // initQueue(&Q);
    printf("\nBFS:");
    BFS(G, 0);

    printf("\nDFS:");
    printf("\n");
    DFS(G, 0);

    printf("\n\nDisplaying Degree:");
    displayDegree(G);

    printf("\n\nChecking if Graph is Connected:");
    if(verifyIfGraphIsConnected(G)){
        printf("\nGraph is Connected!\n");
    }else{
        printf("\nGraph is not Connected!\n");
    }

    // printf("\n\nNumber of Components:");    
    // printf("\n%d\n", numberOfComponents(G));

    printf("\nComponents:\n");    
    numberOfComponents(G);

    // printf("\n\nDisplaying Cycles:");
    // displayCycles(G);


    printf("\n\nWorking Well!\n");
    return 0;
}