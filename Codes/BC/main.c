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
    display(result);

    seperator();
    
}