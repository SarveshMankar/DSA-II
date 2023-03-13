typedef struct node {
    int data;
    struct node *left,*right;
} node;

typedef node *BT;

void initBT(BT *t);

void insertBST(BT *t, int key);
int searchBST(BT t, int key, int count);

void insertBT(BT *t, int key);


void inorder(BT t);