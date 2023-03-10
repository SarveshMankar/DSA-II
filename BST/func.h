typedef struct node
{
    int data;
    struct node *left, *right;
} node;


typedef node* BST;

void initBST(BST *t);