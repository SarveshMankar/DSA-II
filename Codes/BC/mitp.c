#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#include<ctype.h>

char stack[100];
int top = -1;

char ansString[100];

void push(char x)
{
    stack[++top] = x;
    printf(" ");
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main(){
    // char *exp="(a+b)*c+(d-a)";;
    char *exp="(100+45)*6+(45-12)";
    char *e, x, t;
    char ans[100];
    int k = 0 ;
    int i = 0;
    printf("\n");
    e = exp;
    
   
    while(*e != '\0')
    {
        
        if(isalnum(*e)){
            x=*e;
            // printf("%c",x); 
             ans[k++] = x;
        }
        else if(*e == '('){
            
            push(*e);
        }
        else if(*e == ')'){
            while((x = pop()) != '('){
                    ans[k++] = ' ';
                 ans[k++] = x;
                     ans[k++] = ' ';
            }
           
                // printf(" %c ", x);
                            
                
        }
        else
        {
            ans[k++] = ' ';
            while(priority(stack[top]) >= priority(*e)){
                t=pop();

                 ans[k++] = t;
                      ans[k++] = ' ';
            }
            //  ans[k++] = ' ';
            push(*e);
        }
        e++;
        i++;

    }
    
    while(top != -1){
        x=pop();
        // printf("%c ",x);
         ans[k++] = x;
    }
    
    printf("\n%s",ans);
    return 0;
}
