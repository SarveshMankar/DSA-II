#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"func.h"
#include"queue.h"
#include"stack.h"


void initGraph(graph *G, char *filename){
    FILE *fp;
    fp = fopen(filename, "r");

    fscanf(fp, "%d", &G->n);
    G->A = (int**)malloc(G->n*sizeof(int*));

    for(int i = 0; i < G->n; i++){
        G->A[i] = (int*)malloc(G->n*sizeof(int));
        if(!G->A[i]){
            printf("Not enough memory!\n");
            exit(0);
        }
        for(int j = 0; j < G->n; j++){
            fscanf(fp, "%d", &G->A[i][j]);
        }
    }   

    fclose(fp);
}

void display(graph G){
    for(int i = 0; i < G.n; i++){
        for(int j = 0; j < G.n; j++){
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}

void BFS(graph G, int s){
    int *visited = (int*)calloc(G.n,sizeof(int));

    Queue Q;
    initQueue(&Q);

    enqueue(&Q, s);
    visited[s] = 1;
    int v;

    while (!isEmpty(&Q)){
        v = dequeue(&Q);
        printf("%d ", v);

        for(int i = 0; i < G.n; i++){
            if(G.A[v][i] != 0 && visited[i] == 0){
                enqueue(&Q  , i);
                visited[i] = 1;
            }
        }
    }
    printf("\n"); 
}


void DFS(graph G, int v){
	int *visited = (int*)calloc(G.n, sizeof(int));
	if(!visited){
		return;
	}

	stack *ms;
	ms = (stack*)malloc(sizeof(stack));
	initStack(ms);

	push(ms, v);
	visited[v] = 1;
	int n, s = G.n;
	while(!isEmptyS(ms)){
		n = pop(ms);
		printf("%d ", n);
		for(int i = 0; i < s; i++){
			if(G.A[n][i] != 0 && !visited[i]){
				push(ms, i);
				visited[i] = 1;
			}
		}
	}
	return;
}

void displayDegree(graph G){
    int s=G.n;
    for (int i=0; i<s; i++){
        int count=0;
        for (int j=0; j<s; j++){
            if (G.A[i][j]!=0){
                count++;
            }
        }
        printf("Degree of %d is %d\n", i, count);
    }
}

void checkIfVertexsAreAdjacent(graph G, int u, int v){
    if (G.A[u][v]!=0){
        printf("Vertex %d and %d are adjacent\n", u, v);
    }
    else{
        printf("Vertex %d and %d are not adjacent\n", u, v);
    }
}

int verifyIfGraphIsConnected(graph G){
    int s=G.n;
    int count = 0;
    for (int i=0; i<s; i++){
        for (int j=0; j<s; j++){
            if (G.A[i][j]!=0){
                count++;
            }
        }
    }
    if (count/2>=s){
        return 1;
    }
    else{
        return 0;
    }
}

void displayCycles(graph G){
    int s=G.n;
    int *visited = (int*)calloc(s, sizeof(int));
    if(!visited){
        return;
    }
    stack *ms;
    ms = (stack*)malloc(sizeof(stack));
    initStack(ms);
    int n;
    for (int i=0; i<s; i++){
        if (!visited[i]){
            push(ms, i);
            visited[i] = 1;
            while(!isEmptyS(ms)){
                n = pop(ms);
                printf("%d ", n);
                for(int i = 0; i < s; i++){
                    if(G.A[n][i] != 0 && !visited[i]){
                        push(ms, i);
                        visited[i] = 1;
                    }
                }
            }
            printf("\n");
        }
    }
    return;
}

void numberOfComponents(graph G){
    // if(verifyIfGraphIsConnected(G)){
    //     return 1;
    // }

    int *visited = (int*)calloc(G.n, sizeof(int));
    if(!visited){
        return;
    }

    stack *ms;
    ms = (stack*)malloc(sizeof(stack));
    initStack(ms);

    push(ms, 0);
    visited[0] = 1;
    printf("%d ", 0);

    for (int i=0; i<G.n; i++){
        if(!visited[i]){
            Queue Q;
            initQueue(&Q);

            enqueue(&Q, i);
            visited[i] = 1;
            int v;

            while (!isEmpty(&Q)){
                v = dequeue(&Q);
                printf("%d ", v);

                for(int j = 0; j < G.n; j++){
                    if(G.A[v][j] != 0 && visited[j] == 0){
                        enqueue(&Q  , j);
                        visited[j] = 1;
                    }
                }
            }
            printf("\n");
        }
    }
    
}