#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define max 30
#include<string.h>
int precedence(char elem);
void push(char elem);
char pop();
int assosiativity(char elem);


char stack[max];
int top=-1;

int main()
{
    char prefix[max],infix[max],ch,elem;
    int i=0,j=0;

    printf("enter the expression\n");
    scanf("%s",infix);
    strrev(infix);
    push('#');
    for(i=0;i<strlen(infix);i++){
        ch=infix[i];
        if(isalnum(ch)){
            prefix[j++]=ch;
        }
        else{
            if(ch==')'){
                push(ch);
            }
            else if(ch=='('){
                while(stack[top]!=')'){
                    prefix[j++]=pop();
                }
                pop();
            }
            else{
                while(precedence(stack[top])>=precedence(ch)){
                    if(precedence(stack[top])==precedence(ch) && assosiativity(ch)==0)
                        prefix[j++]=pop();
                    else if(precedence(stack[top])==precedence(ch) && assosiativity(ch)==1){
                        goto ll;
                    }
                    else if(precedence(stack[top])>precedence(ch))
                        prefix[j++]=pop();

                }
                ll:{
                    push(ch);
                }
            }
        }
    }

    while(stack[top]!='#'){
        prefix[j++]=pop();
    }
    prefix[j]='\0';

    printf("the result is \n\n%s",strrev(prefix));
}

int precedence(char elem)
{
    switch(elem)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        case ')': return 0;
        case '#': return 0;
    }
}

void push(char elem)
{
    stack[++top]=elem;
}

char pop()
{
    return stack[top--];
}

int assosiativity(char elem)
{
    if(elem=='^')
        return 0;
    else
        return 1;
}








