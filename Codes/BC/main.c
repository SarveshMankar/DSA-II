#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"func.c"

void main(){
    char str[]="123+45678";
    int len=strlen(str);

    node *head1 = (node*)malloc(sizeof(node));
    head1=NULL;
    int i;
    for(i=len-1;i>=0;i--){
        if (isOperator(str[i])){
            break;
        }else{
            append(&head1,str[i]-'0');
        }
    }

    node *head2 = (node*)malloc(sizeof(node));
    head2=NULL;
    i=i-1;
    for(i;i>=0;i--){
        if (isOperator(str[i])){
            break;
        }else{
            append(&head2,str[i]-'0');
        }
    }

    printHeads(head1,head2);
    node *result = (node*) malloc(sizeof(node));
    result = NULL; 
    add(head1,head2,result);


}