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
    int flag=0;

    printf("bc 0.0.1");
    printf("\nDeveloped by: Sarvesh Mankar\n");

    while(1){
        // printf("Enter the expression:\t");
        scanf(" %[^\n]s", exp);

        char *ans = malloc (sizeof (char) * 100);
        makePostfixEqation(exp,ans);

        // printf("\n%s", ans);
        str=removeBlanks(ans);
        // printf("\n%s", str);


        LL *head = NULL;
        LL *n1,*n2,*n3;

        head = makeIt(str, head);

        node *result=(node *)malloc(sizeof(node));
        result=NULL;

        LL *traverse = (LL *)malloc(sizeof(LL));
        traverse = head;

        if(isInValidEquation(head)==1){
            // flag=1;
            printf("Invalid Equation! (Hint: Check the Operators!)\n");
            continue;
        }

        while(countLLNodes(head)!=1){
            if(traverse->n1!=NULL && traverse->next->n1!=NULL && traverse->next->next->op!=NULL){
                result=NULL;

                if(traverse->next->next->op->op=='/'){
                    if(checkIfZero(traverse->next->n1)){
                        printf("Runtime error (func=(main), adr=9): Divide by zero\n");
                        flag=1;
                        break ; 
                    }
                }

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

        // printf("\nAnswer:\t");

        if(flag==1){
            flag=0;
        }else{
            node *mainOutput = (node *) malloc(sizeof(node));
            mainOutput = reverse(head->n1);
            display(mainOutput);
            printf("\n");
            // free(mainOutput);
        }

        // free(ans);
        // free(result);
        // free(traverse);
    }
}