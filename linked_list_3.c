#include<stdio.h>
#include<stdlib.h>
void insert(int value);
void print();
typedef struct node Node;
struct node
{
    int data;
    Node* link;
};
Node *head;
void insert(int value)
{
    Node * temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=value;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node *temp1;//=(struct node*)malloc(sizeof(struct node));
        temp1=head;
        while(temp1->link!=NULL){
            temp1=temp1->link;
        }
        temp1->link=temp;

    }
}

void print()
{
    Node* temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}

int main()
{
    head=NULL;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    print();
    //delet(2);
    //printf("\n\n\n\n\n");
    //print();
    printf("\n\n\n\n\n");
    shorting(13);
    print();
}

void delet( int position)
{

    if(position==1){
        struct node *temp;
        temp=head;
        head=head->link;
        free(temp);
    }
    else{
    struct node *temp1;
    struct node *temp2;
    temp1=head;
    for(int i=1;i<=position-2;i++){
        temp1=temp1->link;
    }
    temp2=temp1->link;
    temp1->link=temp2->link;
    free(temp2);
    }

}

void shorting(int value)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL || temp->data<head->data){
        temp->link=head;
        head=temp;
    }

    else{
        //printf("likhon\n");
        struct node *temp1,*temp2;
        temp1=head;
        temp2=temp1->link;
        while(temp2!=NULL && temp->data>temp2->data){
            temp1=temp2;
            //printf("%d\n",temp2->data);
            temp2=temp2->link;
        }
        temp->link=temp1->link;
        temp1->link=temp;
        //temp1->link=temp;
        //temp->link=temp2;
    }
}
