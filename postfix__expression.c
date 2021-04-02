#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#define max 30

char stacks[max];
int top=-1;

int precedence(char elem)
{
    switch(elem)
    {
        case '+' : return 1;
        case '-' : return 1;
        case '*' : return 2;
        case '/' : return 2;
        case '^' : return 3;
        case '(' : return 0;
        case '#' : return 0;
        //case '+' : return 1;
    }
}

void push(char ch)
{
    stacks[++top]=ch;
}

char pop()
{
    return stacks[top--];
}

int assosiativity(char item)
{
    if(item=='^')
        return 0;
    else
        return 1;
}


int main()
{
    char infix[max],postfix[max],ch,elem;
    int i=0,j=0;

    printf("Enter the infix expression\n");
    scanf("%s",infix);

    push('#');

    for(i=0;i<strlen(infix);i++){
        ch=infix[i];
        if(isalnum(ch))
            postfix[j++]=ch;
        else{
            if(ch=='(')
                push(ch);
            else if(ch==')'){
                while(stacks[top]!='('){
                    postfix[j++]=pop();
                }
                pop();
            }
            else{
                while(precedence(stacks[top])>=precedence(ch)){
                    if(precedence(stacks[top])==precedence(ch) && assosiativity(ch)==0){
                        goto ll;
                    }
                    else
                        postfix[j++]=pop();
                }
                ll:{
                push(ch);
                }
            }
        }
    }
    while(stacks[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("The resust is:\n\n%s",postfix);
}
























