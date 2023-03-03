#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"func.h"

void append(node **head, int data){
    node *nn = (node *)malloc(sizeof(node));
    nn->data=data;
    nn->next=NULL;

    if(*head==NULL){
        *head=nn;
    }else{
        node *temp = (node *)malloc(sizeof(node));
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }
}

void evaluate(char str[], node **head1, node **head2){
    int len=strlen(str);

    int j=0;
    while (!(isOperator(str[j])))
        j++;
    //printf("Operator Index=%d",j);
    
    int i=j-1;
    for(i;i>=0;i--){
        if (isOperator(str[i])){
            break;
        }else{
            append(&(*head1),str[i]-'0');
        }
    }

    i=len-1;
    for(i;i>=j;i--){
        if (isOperator(str[i])){
            break;
        }else{
            append(&(*head2),str[i]-'0');
        }
    }
}

void display(node *head){
    while (head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
}

int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^'){
        return 1;
    }else{
        return 0;
    }
}

void addZeros(node *head1, node *head2){
    int c1=0;
    node *temp = (node*) malloc(sizeof(node));
    temp=head1;
    while (temp!=NULL){
        c1++;
        temp=temp->next;
    }
    //printf("c1=%d\t",c1);

    int c2=0;
    temp=head2;
    while (temp!=NULL){
        c2++;
        temp=temp->next;
    }
    //printf("c2=%d\t",c2);
    
    int i;
    if (c1>c2){
        for(i=c2;i<c1;i++){
            append(&(head2),0);
        }
    }else{
        for(i=c1;i<c2;i++){
            append(&(head1),0);
        }
    }
    append(&(head1),0);
    append(&(head2),0);
}

node *add(node *head1, node *head2, node *result){
    addZeros(head1,head2);
    printHeads(head1,head2);

    int carry=0;
    char c1[2];
    int ans;

    while(head1!=NULL){
        ans=head1->data+head2->data+carry;
        if(ans>=10){
            carry=1;
            ans=ans-10;
        }else{
            carry=0;
        }
        append(&result,ans);

        head1=head1->next;
        head2=head2->next;
    }

    return result;
}

void borrow(node **head1){
    node *temp = (node *)malloc(sizeof(node));
    temp = *head1;
    if(temp->next->data-1<0){
        borrow(&temp->next);
    }
    temp->next->data=temp->next->data-1;
    temp->data=temp->data+10;
    //printf("\n");display(temp);printf("\n");
}

node *subtract(node *head1, node *head2, node *result){
    addZeros(head1,head2);
    printHeads(head1,head2);
    //borrow(&head1);

    while (head1!=NULL){
        if(head1->data-head2->data<0){
            borrow(&head1);
        }
        append(&result,head1->data-head2->data);
        //printf("%d-%d \t", head1->data, head2->data);

        head1=head1->next;
        head2=head2->next;
    }
    //printf("\nMain Answer:\n");
    //display(result);

    return result;
}

void displayAnswer(node *result){
    node *prev= NULL;
    node *curr= result;
    node *next= NULL;

    while (curr != NULL) {
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }
    result = prev;

    while (result!=NULL){
        printf("%d",result->data);
        result=result->next;
    }
    
}

void printHeads(node *head1, node *head2){
    printf("\n");
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
}

void seperator(){
    printf("\n-----------------------------\n");
}
