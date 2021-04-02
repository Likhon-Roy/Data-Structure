#include<stdio.h>
#include<string.h>
#include<conio.h>
void push(char ch);
char pop();

#define length 50

char str[length];
char strpush[length];
int top=-1;


int main()
{
    printf("enter the string\n");
    scanf(" %[^\n]",str);

    for(int i=0;i<strlen(str);i++){
        push(str[i]);
    }

    for(int i=0;i<strlen(str);i++){
        str[i] = pop();
    }
    printf("%s\n",str);
    puts(str);
}

void push(char ch)
{
    if(top==length-1){
        printf("wrong");
    }
    else{
        strpush[++top]=ch;
    }
}

char pop()
{
    if(top==-1){
        printf("no element");
    }
    else{
        return strpush[top--];
    }
}















