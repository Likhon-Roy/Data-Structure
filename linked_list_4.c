#include<stdio.h>
#include<stdlib.h>
void print();
void insert(int value);
struct node
{
    int data;
    struct node*link;
};
typedef struct node Node;

Node* head=NULL;

int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        insert(a);
    }
    print();
}

void insert(int value)
{
    Node* temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=value;
    temp->link=head;
    head=temp;

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
