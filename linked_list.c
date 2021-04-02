#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
//using namespace std;
struct node
{
    int data;
    struct node * link;
};

struct node* head;

void print()
{
    struct node* temp;
    temp=head;
    while(temp !=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}

int main()
{
    int n,a;
    //struct node *temp;
    //temp=head;
    head=NULL;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        head=(struct node*)malloc(sizeof(struct node));

        scanf("%d",&);
        head=head->link;
    }


    /*head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->link=(struct node*)malloc(sizeof(struct node));
    head->link->data=20;
    //head->link->link=NULL;
    head->link->link=(struct node*)malloc(sizeof(struct node));
    head->link->link->data=30;
    head->link->link->link=NULL;*/
    print();
    return 0;
}
