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
        printf("%d",head->data);
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

node *removeZeros(node *head){
    printf("\nHead:");
    display(head);
    seperator();

    node *rhead=(node *)malloc(sizeof(node));
    rhead=reverse(head);
    printf("\nReversed Head:");
    display(rhead);
    seperator();

    node *rtemp = (node *)malloc(sizeof(node));
    rtemp=rhead;
    if(rtemp->next->next!=NULL && rtemp->data==0 && rtemp->next->data==0){
        while (rtemp->next->next!=NULL && rtemp->next->next->data==0){
            rtemp=rtemp->next;
        }   
        rhead=rtemp->next;
    }


    printf("\nAns Head:");
    display(rhead);
    seperator();

    rhead=reverse(rhead);
    printf("\nReturn Ans Head:");
    display(rhead);
    seperator();

    return rhead;
}

node *removeAllZeros(node *head){
    printf("\nHead:");
    display(head);
    seperator();

    node *rhead=(node *)malloc(sizeof(node));
    rhead=reverse(head);
    printf("\nReversed Head:");
    display(rhead);
    seperator();

    node *rtemp = (node *)malloc(sizeof(node));
    rtemp=rhead;
    if(rtemp->next!=NULL){
        while (rtemp->next!=NULL && rtemp->next->data==0)
        {
            rtemp=rtemp->next;
        }   
    }

    rhead=rtemp->next;

    printf("\nAns Head:");
    display(rhead);
    seperator();

    rhead=reverse(rhead);
    printf("\nReturn Ans Head:");
    display(rhead);
    seperator();

    return rhead;
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
    //head1=removeZeros(head1);
    //head2=removeZeros(head2);
    /*printf("\nMain Ans Head:");
    display(head1);
    seperator();
    printf("\nMain Ans Head:");
    display(head2);
    seperator();*/
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
    result=removeZeros(result);

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
    result=removeZeros(result);
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

node *addPlaceZeros(node *sAns, node *zeros){
    node *nn = (node *)malloc(sizeof(node));
    nn=NULL;
    node *tempn = (node *)malloc(sizeof(node));
    tempn=sAns;
    sAns=nn;
    while (zeros!=NULL){
        append(&nn,zeros->data);
        zeros=zeros->next;
    }

    node *zt1 = (node *)malloc(sizeof(node));
    zt1=nn; 
    while (zt1->next!=NULL)
    {
        zt1=zt1->next;
        printf("S");
    }
    
    zt1->next=tempn;
    return nn;
}

node *multiply(node *head1, node *head2, node *result){
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
    node *zAns = (node *)malloc(sizeof(node));
    zAns=NULL;
    node *pAns = (node *)malloc(sizeof(node));
    pAns=NULL;
    node *nAns = (node *)malloc(sizeof(node));
    nAns=NULL;

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
                //printf("\nMultiplication Ans= %d",mAns->data);
                append(&sAns,mAns->data);
                mCarry = mAns->next;
            }else{
                tempAns = add(mAns,mCarry,tempAns);
                printf("\nAnswer has Carry:");
                display(tempAns);
                //printf("\nMultiplication Ans has Carry= %d",tempAns->data);
                append(&sAns,tempAns->data);
                mCarry=NULL;
                mCarry = tempAns->next;
            }

            //mCarry = mAns->next;
            printf("\nCarry:");
            display(mCarry);

            temp1=temp1->next;
            mAns=NULL;
            tempAns=NULL;
            printf("\n");
            //if(sAns->data==0 && (mCarry->data==0 || mCarry==NULL) && temp1->data*temp2->data==0 && zAns==NULL){
            //    break;
            //}
        }

        if(zAns==NULL){
            append(&zAns,0);
            printf("Zeros: ");
            display(zAns);
        }else{
            sAns = addPlaceZeros(sAns,zAns);
            printf("Zeros: ");
            display(zAns);
            append(&zAns,0);
        }

        if(pAns==NULL){
            pAns=sAns;
        }else{
            nAns=add(pAns,sAns,nAns);
            pAns=nAns;
            printf("\nAdd Ans: ");
            display(nAns);
            nAns=NULL;
        }
        

        printf("Main Answer: ");
        display(sAns);
        sAns=NULL;
        temp2=temp2->next;
        printf("\n");
        
        seperator();
    }
    printf("My Main Multiplication Answer: ");
    removeAllZeros(pAns);
    display(pAns);

    
    return pAns;
}

node * reverse(node *head1){
    node *temp = (node *)malloc(sizeof(node));
    temp=head1;

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

    return temp;
}

node *makeList(char str[]){
    int len = strlen(str);

    node *mn = (node *)malloc(sizeof(node));
    mn=NULL;

    for(int i=0;i<len;i++){
        append(&mn,str[i]-'0');
    }

    return mn;
}

int compare(node *head1, node *head2){
    
    node *rtemp = (node *)malloc(sizeof(node));

    rtemp=head1;
    node *rhead1 = (node *)malloc(sizeof(node));
    rhead1=NULL;
    while (rtemp!=NULL){
        append(&rhead1,rtemp->data);
        rtemp=rtemp->next;
    }
    
    rtemp=head2;
    node *rhead2 = (node *)malloc(sizeof(node));
    rhead2=NULL;
    while (rtemp!=NULL){
        append(&rhead2,rtemp->data);
        rtemp=rtemp->next;
    }

    addZeros(rhead1,rhead2);

    //printf("\nHead 1: Function Reversed: ");
    //display(rhead1);
    rhead1=reverse(rhead1);

    //printf("\nHead 2: Function Reversed: ");
    //display(rhead2);
    rhead2=reverse(rhead2);

    //printf("\nHead 1: Function Proper: ");
    //display(rhead1);

    //printf("\nHead 2: Function Proper: ");
    //display(rhead2);

    int flag = 0;
    //head1>head2 -> flag=1
    //head2>head1 -> flag=-1
    //head1=head2 -> flag=0

    while (rhead1!=NULL){
        if(rhead1->data>rhead2->data){
            flag=1;
            break;
        }else if (rhead2->data>rhead1->data){
            flag=-1;
            break;
        }
        rhead1=rhead1->next;
        rhead2=rhead2->next;
    }
    //printf("Flag=%d",flag);
    return flag;
}

void raiseTo(node *head1, node *head2){
    int flag = compare(head1,head2);
    /*node *forSwap = (node *)malloc(sizeof(node));
    forSwap=NULL;
    if (flag==-1){
        forSwap=head1;
        head1=head2;
        head2=forSwap;
    }*/

    node *c = (node *)malloc(sizeof(node));
    c=NULL;
    c=makeList("1");
    printf("\nc: ");
    display(c);

    node *o = (node *)malloc(sizeof(node));
    o=makeList("1");
    node *t = (node *)malloc(sizeof(node));
    t=NULL;

    node *tAns = (node *)malloc(sizeof(node));
    tAns=NULL;
    node *ans = (node *)malloc(sizeof(node));
    ans=head1;
    while (compare(head2,c)){
        //printf("Hello-");
        c=add(c,o,t);
        ans=multiply(ans,head1,tAns);
    }

    printf("\nFunction Raise to answer: ");
    display(ans);
    
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
