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

    int c2=0;
    temp=head2;
    while (temp!=NULL){
        c2++;
        temp=temp->next;
    }
    
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
    //printHeads(head1,head2);

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
}

node *subtract(node *head1, node *head2, node *result){
    addZeros(head1,head2);
    printHeads(head1,head2);

    while (head1!=NULL){
        if(head1->data-head2->data<0){
            borrow(&head1);
        }
        append(&result,head1->data-head2->data);

        head1=head1->next;
        head2=head2->next;
    }
    return result;
}

node *makeAns(char str[], node **mAns){
    int len = strlen(str);
    int i=len-1;

    for(i;i>=0;i--){
        append(&(*mAns),str[i]-'0');
    }
    return *mAns;
}

/*node *makeMulAns(node **head, int data){
    node *n = (node*)malloc(sizeof(node));
    n->data=data;
    n->next=NULL;
    if(*head==NULL){
        
    }
}*/

void multiply(node *head1, node *head2, node *result){
    addZeros(head1,head2);
    node *temp1 = (node *)malloc(sizeof(node));
    node *temp2 = (node *)malloc(sizeof(node));
    temp2=head2;

    int ans;
    char str[100];
    node *mCarry = (node *)malloc(sizeof(node));
    mCarry=NULL;
    node *mAns = (node *)malloc(sizeof(node));
    mAns=NULL;
    node *sAns = (node *)malloc(sizeof(node));
    sAns=NULL;
    node *tempAns = (node *)malloc(sizeof(node));
    tempAns=NULL;

    while (temp2!=NULL){
        temp1=head1;
        mCarry=NULL;
        mAns=NULL;  
        tempAns=NULL;  
        while (temp1!=NULL){
            printf("\nMul=");
            ans=temp1->data*temp2->data;

            sprintf(str, "%d", ans);
            printf("%s\t",str);

            mAns = makeAns(str, &mAns);

            if(mCarry==NULL){
                printf("\nAnswer:");
                display(mAns);
                printf("\nMultiplication Ans= %d",mAns->data);
            }else{
                tempAns = add(mAns,mCarry,tempAns);
                printf("\nAnswer has Carry:");
                display(tempAns);
                printf("\nMultiplication Ans has Carry= %d",tempAns->data);
                mCarry=NULL;
            }

            /*if(mCarry!=NULL){
                printf("\nMultiplication Ans has Carry= %d",tempAns->data);
                //append(&sAns,tempAns->data);
            }else{
                printf("\nMultiplication Ans= %d",mAns->data);
                //append(&sAns,mAns->data);
            }*/

            mCarry = mAns->next;
            printf("\nCarry:");
            display(mCarry);

            temp1=temp1->next;
            mAns=NULL;
            tempAns=NULL;
            printf("\n");
        }
        temp2=temp2->next;
        printf("\n");
        seperator();
    }
    
}

void displayAnswer(node *result){
    node *temp = (node *)malloc(sizeof(node));
    temp=result;

    node *prev= NULL;
    node *curr= temp;
    node *next= NULL;

    while (curr != NULL) {
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }
    temp = prev;

    while (temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
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
