#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"func.c"

void main(){
    char str[]="45678+123";

    node *head1 = (node*)malloc(sizeof(node));
    head1=NULL;

    node *head2 = (node*)malloc(sizeof(node));
    head2=NULL;
    
    evaluate(str,&head1,&head2);

    printHeads(head1,head2);
    node *result = (node*) malloc(sizeof(node));
    result = NULL; 
    result = add(head1,head2,result);
    printf("\n");
    display(result);
    printf("\n%s=",str);
    displayAnswer(result);

    seperator();
    
    char str1[]="45801-123";
    head1=head2=NULL;
    evaluate(str1,&head1,&head2);
    printHeads(head1,head2);
    result=NULL;
    result = subtract(head1,head2,result);
    printf("\n");
    display(result);
    printf("\n%s=",str1);
    displayAnswer(result);
}