typedef struct node
{
    int data;
    struct node *left, *right;
} node;


typedef node* BST;

typedef struct stack{
    node *data;
    struct stack *next;
    struct stack *top;
}stack;

// void initStack(stack **s);
void initStack(stack *s);
void push(stack *s,node *data);
node *pop(stack *s);
stack *destroyStack(stack *s);

void initBST(BST *t);
void insertWithRecursion(BST *t, int key);
void insertWithoutRecursion(BST *t, int key);
void insertBT(BST *t, int key);

void inOrderWithRecursion(BST t);
void inOrderWithoutRecursion(BST t);

void preOrderWithRecursion(BST t);
void preOrderWithoutRecursion(BST t);

void postOrderWithRecursion(BST t);
void postOrderWithoutRecursion(BST t);

int countNodesWithRecursion(BST t);
int countNodesWithoutRecursion(BST t);

int countLeafNodesWithRecursion(BST t);
int countLeafNodesWithoutRecursion(BST t);

int countInternalNodesWithRecursion(BST t);
int countInternalNodesWithoutRecursion(BST t);

int isFullTreeWithRecursion(BST t);
int isFullTreeWithoutRecursion(BST t);

int isCompleteTreeWithoutRecursion(BST t);

int isBST(BST t);

int height(BST t);

void destroyWithRecursion(BST *t);
node *destroyWithoutRecursion(BST t);

int countLevelNodes(node *t, int curr, int tl);
int breadthRecusrion(BST t);




int D_height(node* t);
int diameterOfBinaryTree(node* root);