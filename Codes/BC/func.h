typedef struct node
{
    int data;
    struct node* next;
} node;

void append(node **head, int data);
void evaluate(char str[], node **head1, node **head2);
int isOperator(char c);
void addZeros(node *head1, node *head2);
node *add(node *head1, node *head2, node *result);
node *subtract(node *head1, node *head2,node *result);
void borrow(node **head1);

void printHeads(node *head1, node *head2);
void seperator();

void displayAnswer(node *result);