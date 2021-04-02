#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#define max_stack 10

typedef struct stack
{
    int top;
    int data[max_stack];
}STACK;

void push(STACK *s,int item);
int pop(STACK *s);
void display(STACK *s);

int main()
{
    STACK my_stack;
    int item;
    int a;

    my_stack.top=0;

    while(1){
        scanf("%d",&a);

        switch(a)
        {
            case 1 :printf("enter the element\n");
                    scanf("%d",&item);
                    push(&my_stack,item);
                    //display(&my_stack);
                    break;
            case 2 :item=pop(&my_stack);
                    printf(".........%d\n",item);
                    //display(&my_stack);
                    break;
            case 4 ://pop(&my_stack);
                    display(&my_stack);
                    break;
            case 3 :exit(0);
        }
    }

    /*push(&my_stack,10);
    push(&my_stack,20);
    push(&my_stack,30);


    item=pop(&my_stack);
    printf("%d\n",item);

    item=pop(&my_stack);
    printf("%d\n",item);

    item=pop(&my_stack);
    printf("%d\n",item);*/
}

void display(STACK *s)
{
    for(int i=0;i<s->top;i++){
        printf("%d\n",s->data[i]);
    }
}


void push(STACK *s,int item)
{
    if(s->top>max_stack){
        printf("error");
    }
    else{
        s->data[s->top]=item;
        s->top=s->top+1;
    }
}

int pop(STACK *s)
{
    int item;
    if(s->top==0){
        printf("wrong");
        return -1;
    }
    else{
        s->top=s->top-1;
        //item=s->data[s->top];
    }
    return s->data[s->top];
}












