#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"func.c"

void main(){
    node *head1 = (node*)malloc(sizeof(node));
    head1=NULL;

    node *head2 = (node*)malloc(sizeof(node));
    head2=NULL;

    node *result = (node*) malloc(sizeof(node));
    result = NULL; 
    

    /*
    char str[]="9999+10";
    evaluate(str,&head1,&head2);
    printHeads(head1,head2);

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

    char str3[]="1999-2";
    head1=head2=NULL;
    evaluate(str3,&head1,&head2);
    printHeads(head1,head2);
    result=NULL;
    result = subtract(head1,head2,result);
    printf("\n");
    display(result);
    printf("\n%s=",str3);
    displayAnswer(result);*/

    //char str1[] = "54*67";
    //char str1[] = "6793*8542";
    //char str1[] = "123*11";
    //char str1[] = "16871414614687414418451341654168*148618978465413987";

    /*evaluate(str1,&head1,&head2);
    printHeads(head1,head2);
    result = multiply(head1,head2,result);
    printf("\nMain Function Answer: ");
    display(result);*/

    /*char str1[] = "10^10";
    evaluate(str1,&head1,&head2);
    
    printf("\nHead 1: Reversed: ");
    display(head1);

    printf("\nHead 2: Reversed: ");
    display(head2);

    raiseTo(head1,head2);*/

    //char str1[] = "6756454593*854455158715168379468712";
    //char str1[] = "123*11";
    //char str1[] ="6793*8542";
    
    //char str1[] = "16871414614687414418451341654168*148618978465413987";
    
    /*char str1[] ="6793*8542";
    evaluate(str1,&head1,&head2);

    printHeads(head1,head2);
    result = multiply(head1,head2,result);
    printf("\nMain Function Answer: ");
    display(result);*/
    
    /*char str1[] ="000001+00000000000000005773087481613643376229746092194216";
    evaluate(str1,&head1,&head2);
    result=add(head1,head2,result);
    display(result);
    seperator();*/

    /*char str1[] = "10^20";
    evaluate(str1,&head1,&head2);
    raiseTo(head1,head2);*/

    /*
    Subtract
    char str3[]="1100-1100";
    head1=head2=NULL;
    evaluate(str3,&head1,&head2);
    printHeads(head1,head2);
    result=NULL;
    result = subtract(head1,head2,result);
    printf("\n");
    display(result);
    printf("\n%s=",str3);
    displayAnswer(result);*/

}
