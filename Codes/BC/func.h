typedef struct node
{
    int data;
    struct node* next;
} node;

void append(node **head, int data);
int isOperator(char c);
void addZeros(node *head1, node *head2);
void printHeads(node *head1, node *head2);
void add(node *head1, node *head2, node *result);