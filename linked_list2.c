#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void print();
void insert(int value);

struct node
{
    int data;
    struct node * link;
};
struct node * head;
int main()
{
    head=NULL;
    insert(1);
    insert(4);
    insert(3);
    print();
    return 0;
}
void insert(int value)
{
    //struct node * temp
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("allocation error");
        exit(0);
    }
    temp->data=value;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node * t;
        t=head;
        while(t->link!=NULL){
            t=t->link;
        }
        t->link=temp;
    }
}
void print()
{
    struct node * temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
