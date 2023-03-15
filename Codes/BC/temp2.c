#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.c"

// typedef struct operator{
//     char op;
// } operator;

// typedef struct LL{
//     node *n1;
//     operator *op;
//     struct LL *next;
// } LL;

void displayNode(node *n1){
    node *temp = n1;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void displayLL(LL *head){
    LL *temp = head;
    while(temp != NULL){
        if (temp->n1 != NULL){
            displayNode(temp->n1);
            printf("\n");
        }
        if (temp->op != NULL){
            printf("%c", temp->op->op);
            printf("\n");
        }
        temp = temp->next;
    }
}

void appendLL(LL **head, node *n1, operator *op){
    LL *newNode = (LL *)malloc(sizeof(LL));
    newNode->n1 = n1;
    newNode->op = op;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }
    else{
        LL *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

LL *makeIt(char str[], LL *head){
    int len = strlen(str);

    node *n1 = (node *)malloc(sizeof(node));
    n1=NULL;    

    for(int i=0; i<len; i++){
        // printf("%c\n", str[i]);
        if(!(isOperator(str[i]))){
            if(str[i]!=' '){
                append(&n1, str[i]-'0');
            }
            if (str[i]==' '){
                operator *op = (operator *)malloc(sizeof(operator));
                op=NULL;
                appendLL(&head, n1, op);
                n1=NULL;
            }
        }
        if(isOperator(str[i])){
            operator *op = (operator *)malloc(sizeof(operator));
            op->op = str[i];
            n1=NULL;
            appendLL(&head, n1, op);
            op=NULL;
        }
    }

    return head;
}

void main(){
    char str[] = "100 45 + 6 * 45 12 - +";
    LL *head = NULL;

    head = makeIt(str, head);
    displayLL(head);
    // printf("\nDisplay List:\t");
    // displayLL(head);

    seperator();

    if(head->n1!=NULL && head->next->n1!=NULL && head->next->next->op!=NULL){
        printf("First Solution");
        solve(&head->n1, &head->next->n1, head->next->next->op);
    } 
}