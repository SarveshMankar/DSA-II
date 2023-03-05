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
node *multiply(node *head1, node *head2, node *result);
node *makeAns(char str[], node **mAns);
node *makeMulAns(node **head, int data);
node *addPlaceZeros(node *sAns, node *zeros);

node *reverse(node *head1);
node *makeList(char str[]);
int compare(node *head1, node *head2);
void raiseTo(node *head1, node *head2);
node *removeZeros(node *head);
node *removeAllZeros(node *head);

void printHeads(node *head1, node *head2);
void seperator();

void displayAnswer(node *result);