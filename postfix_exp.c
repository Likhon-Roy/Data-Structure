#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 30

int precedence(char elem);
void push(char elem);
char pop();
int assosiativity(char ch);

char strack[max];
int top=-1;

int main()
{
    char infix[max],postfix[max],ch,elem;
    int i=0,j=0;

    printf("enter the infix expression\n");
    scanf("%s",infix);

    strrev(infix);

    push('#');

    for(i=0;i<strlen(infix);i++){
        ch=infix[i];
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else{
            if(ch==')'){
                push(ch);
               }
            else if(ch=='('){
                while(strack[top]!=')'){
                        postfix[j++]=pop();
                      }
                      elem=pop();
            }
            else{
                while(precedence(strack[top])>=precedence(ch)){
                    if(precedence(strack[top])==precedence(ch) && assosiativity(ch)==0){
                        postfix[j++]=pop();
                    }
                    else if(precedence(strack[top])==precedence(ch) && assosiativity(ch)==1){
                        //continue;
                        //push(ch);
                        goto ll;
                    }
                    else if(precedence(strack[top])>precedence(ch)){
                        postfix[j++]=pop();
                    }


                }
                ll:{
                push(ch);
                //goto kk;
                }
            }
        }
    }

    while(strack[top]!='#'){
        postfix[j++]=pop();
    }

    postfix[j]='\0';

    printf("the result is\n\n%s",strrev(postfix));

}


int precedence(char elem)
{
    switch(elem)
    {
        case '+' : //return 1;
        case '-' : return 1;
        case '*' : //return 2;
        case '/' : return 2;
        case '^' : return 3;
        case ')' : //return 0;
        case '#' : return 0;
    }
}

void push(char elem)
{
    strack[++top]=elem;
}

char pop()
{
    return strack[top--];
}

int assosiativity(char ch)
{
    if(ch=='^')
        return 0;
    else
        return 1;
}










