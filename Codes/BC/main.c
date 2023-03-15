#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include "func.c"

char *str;

void main(){
    char exp[100];
    printf("Enter the expression:\t");
    scanf("%[^\n]s", exp);

    char *ans = malloc (sizeof (char) * 100);
    makePostfixEqation(exp,ans);

    printf("\n%s", ans);
    str=removeBlanks(ans);
    printf("\n%s", str);


    LL *head = NULL;
    LL *n1,*n2,*n3;

    head = makeIt(str, head);

    node *result=(node *)malloc(sizeof(node));
    result=NULL;

    LL *traverse = (LL *)malloc(sizeof(LL));
    traverse = head;

    while(countLLNodes(head)!=1){
        if(traverse->n1!=NULL && traverse->next->n1!=NULL && traverse->next->next->op!=NULL){
            result=NULL;
            result=solve(&traverse->n1, &traverse->next->n1, traverse->next->next->op);

            n1=traverse;
            n2=traverse->next;
            n3=traverse->next->next;

            insertTheSolution(traverse, n3, result);

            removeLLNode(&head, n1);
            removeLLNode(&head, n2);
            removeLLNode(&head, n3);

            traverse=head;
        }else{
            traverse=traverse->next;
        }
    }

    printf("\nAnswer:\t");

    node *mainOutput = (node *) malloc(sizeof(node));
    mainOutput = reverse(head->n1);
    display(mainOutput);
}