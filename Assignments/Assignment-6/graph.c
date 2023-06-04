#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"graph.h"
#include"stack.h"
#include"queue.h"
#include"heap.h"

void init(graph *G, char *filename){
    //Creating Adajacency List
    FILE *fp = fopen(filename,"r");
    fscanf(fp,"%d",&G->n);
    G->A = (node**)malloc(G->n*sizeof(node*));

    for (int i = 0; i < G->n; i++){
        node *row = (node*)malloc(sizeof(node));
        for (int j = 0; j < G->n; j++){
            int x;
            fscanf(fp,"%d",&x);
            if (x != 100){
                node *temp = (node*)malloc(sizeof(node));
                temp->j = j;
                temp->w = x;
                temp->next = NULL;
                if (row->next == NULL){
                    row->next = temp;
                }
                else{
                    node *p = row;
                    while (p->next != NULL){
                        p = p->next;
                    }
                    p->next = temp;
                }
            }
        }
        G->A[i] = row;
    }
    
}

void print(graph *G){
    for (int i = 0; i < G->n; i++){
        node *p = G->A[i]->next;
        while (p != NULL){
            printf("%d ",p->j);
            p = p->next;
        }
        printf("\n");
    }
}

void BFS(graph *G, int s){
    int *visited = (int*)malloc(G->n*sizeof(int));
    for (int i = 0; i < G->n; i++){
        visited[i] = 0;
    }
    
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    initQueue(Q);

    enqueue(Q,s);
    visited[s] = 1;

    while (!isEmpty(Q)){
        int i = dequeue(Q);
        printf("%d ",i);
        node *p = G->A[i]->next;
        while (p != NULL){
            if (visited[p->j] == 0){
                enqueue(Q,p->j);
                visited[p->j] = 1;
            }
            p = p->next;
        }
    }

    printf("\n");
}

void DFS(graph *G, int s){
    int *visited = (int*)malloc(G->n*sizeof(int));
    for (int i = 0; i < G->n; i++){
        visited[i] = 0;
    }
    
    Stack *S = (Stack*)malloc(sizeof(Stack));
    initStack(S);

    push(S,s);
    visited[s] = 1;

    while (!isEmptyS(S)){
        int i = pop(S);
        printf("%d ",i);
        node *p = G->A[i]->next;
        while (p != NULL){
            if (visited[p->j] == 0){
                push(S,p->j);
                visited[p->j] = 1;
            }
            p = p->next;
        }
    }

    printf("\n");
}

void PRIMS(graph *G, int s){
    int *visited = (int*)calloc(G->n,sizeof(int));
    if(!visited) return;
    
    int *parent = (int*)malloc(G->n*sizeof(int));
    for (int i = 0; i < G->n; i++){
        parent[i] = -1;
    }
    if(!parent){
        free(visited);
        return;
    }

    int *cost = (int*)malloc(G->n*sizeof(int));
    if(!cost){
        free(visited);
        free(parent);
        return;
    }

    for (int i = 0; i < G->n; i++){
        cost[i] = INT_MAX;
    }
    cost[s] = 0;
    parent[s] = -1;

    for (int i = 0; i < G->n; i++){
        int min = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < G->n; j++){
            if (visited[j] == 0 && cost[j] < min){
                min = cost[j];
                min_index = j;
            }
        }

        visited[min_index] = 1;

        node *p = G->A[min_index]->next;
        while (p != NULL){
            if (visited[p->j] == 0 && p->w < cost[p->j]){
                cost[p->j] = p->w;
                parent[p->j] = min_index;
            }
            p = p->next;
        }
    }

    for (int i = 0; i < G->n; i++){
        printf("%d %d %d\n",i, parent[i], cost[i]);
    }
}

void KRUSKALS(graph *G, int s){
    int *visited = (int*)calloc(G->n,sizeof(int));
    if(!visited) return;

    int *set = (int*)malloc(G->n*sizeof(int));
    if(!set){
        free(visited);
        return;
    }
    for (int i = 0; i < G->n; i++){
        set[i] = i;
    }

    heap *h = (heap*)malloc(sizeof(heap));
    initHeap(h);
    
}
