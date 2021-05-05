#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE *last;
void display()
{
    NODE *currptr,*temp;
    currptr=last->link;
    while(currptr!=last){
        printf("%d\t",currptr->data);
        currptr=currptr->link;
    }
    printf("%d",currptr->data);
}

int main()
{
    NODE *currptr,*newnode,*temp,*first;
    int N,item,i;
    printf("enter the item num\n");
    scanf("%d",&N);
    newnode=(NODE*)malloc(sizeof(NODE));
    last=newnode;
    for(i=1;i<=N;i++){
        printf("enter the item\n");
        scanf("%d",&newnode->data);
        if(i==N){
            newnode->link=last;
            last=newnode;
            break;
        }
        currptr=(NODE*)malloc(sizeof(NODE));
        newnode->link=currptr;
        newnode=currptr;;
    }
    display();
}






















