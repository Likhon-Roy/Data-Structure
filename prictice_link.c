#include<stdio.h>
#include<stdlib.h>
void print();
void insert(int value, int pos);
void delet(int pos);
void delet(int pos);
void shorting(int value);

struct node
{
    int data;
    struct node *link;
};
typedef struct node Node;

Node *head=NULL;


int main()
{
    Node *cur;
    int n,i;
    printf("enter the number of element\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++){
        cur=(Node*)malloc(sizeof(Node));
        if(cur==NULL){
            printf("mallocation error\n");
        }
        scanf("%d",&cur->data);
        cur->link=NULL;
        if(head==NULL){
            head=cur;
        }
        else{
            Node *temp;
            temp=head;
            while(temp->link!=NULL){
                temp=temp->link;
            }
            temp->link=cur;
        }
    }
    print();
    printf("\n\n\n");
    //insert(15,3);
    //printf("\n\n\n");
    //print();
    shorting(3);
    printf("\n\n\n");
    print();
}

void print()
{
    Node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }

}

void insert(int value, int pos)
{
    int i=1;
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=value;
    if(head==NULL && pos==1){
        //temp->link=head;
        head=temp;
    }
    else if(head!=NULL && pos==1){
        temp->link=head;
        head=temp;
    }
    else{
        Node *temp1,*temp2;
        temp1=head;
        temp2=head->link;
        while(i<pos){
            temp1=temp2;
            temp2=temp2->link;
            i++;
        }
        temp->link=temp1->link;
        temp1->link=temp;


    }
}
void delet(int pos)
{
    int i=1;

    if(head == NULL){
        printf("no element is there\n");
    }
    else if(head != NULL && pos == 1){
        Node *temp;
        temp=head;
        head=head->link;
        printf("the deleted element is: %d\n",head->data);
        free(temp);
    }
    else if(pos ==1 && head->link==NULL){


         printf("the deleted element is: %d\n",head->link);
         head=NULL;
    }
    else
    {
        Node *temp,*temp1,*temp2;
        temp1=head;
        temp2=head->link;
        while(i<pos-1){
            temp1=temp2;
            temp2=temp2->link;
            i++;
        }
        temp=temp2->link;
        temp1->link=temp;
        printf("delete element is: %d\n",temp2->data);
        free(temp2);
    }
}
void shorting(int value)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=value;
    if(head==NULL || temp->data<head->data){
        temp->link=head;
        head=temp;
    }
    else{
        Node *temp1,*temp2;
        temp1=head;
        temp2=head->link;
        while(temp2!=NULL && temp->data>temp2->data){
            temp1=temp2;
            temp2=temp2->link;
        }
        temp1->link=temp;
        temp->link=temp2;
    }
}
