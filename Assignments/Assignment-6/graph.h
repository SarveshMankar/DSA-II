typedef struct node
{
    int j,w;
    struct node *next;
} node;

typedef struct graph
{
    node **A;
    int n;
} graph;

void init(graph *G, char *filename);
void print(graph *G);
void BFS(graph *G, int s);
void DFS(graph *G, int s);

void PRIMS(graph *G, int s);
void KRUSKALS(graph *G, int s);