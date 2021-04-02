#include<stdio.h>
#include<stdlib.h>
/*void insert();
void print();
void delet();
int creat();*/


struct node
{
    int data;
    struct node* link;
};

typedef struct node Node;

Node *head=NULL,*next, *pvr, *cur,*last;

int creat()
{
    int i,n,a;
    printf("enter the nunber how nuch you want to exucuit\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        if(i==0){
            cur=(Node*)malloc(sizeof(Node));
            head=cur;
        }
        else{
            cur->link=(Node*)malloc(sizeof(Node));
            cur=cur->link;
        }
        printf("enter the element : ");
        scanf("%d",&cur->data);
    }

    cur->link=NULL;
    last=cur;
    //printf("%d",*last);
    /*print();
    insert();
    print();
    delet();
    print();*/
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

void insert()
{
    int i=1,pos;
    cur=(Node*)malloc(sizeof(Node*));
    printf("\nenter the value\n");
    scanf("%d",&cur->data);
    printf("enter the position\n");
    scanf("%d",&pos);
    if(pos==1&&head!=NULL){
        cur->link=head;
        head=cur;
    }
    else{
        next=head;
        while(i<=pos){
            pvr=next;
            next=pvr->link;
            i++;
        }
        //if(prv==NULL)
        cur->link=pvr->link;
        pvr->link=cur;
    }
}

void delet()
{
    int c=1,pos;
    printf("enter the position\n");
    scanf("%d",&pos);
    if(head==NULL){
        printf("there is no linked list\n");

    }
    else if(pos==1&&head->link==NULL){

        printf("delete element is %d",head->data);
        head=NULL;
    }
    else if(pos==1&&head->link!=NULL){
        cur=head;
        head=head->link;
        cur->link=NULL;
        printf("the delete list is %d\n",head->data);
        free(cur);
    }
    else{
        next=head;
        while(c<pos){
            cur=next;
            next=cur->link;
            c++;
        }
        cur->link=next->link;
        next->link=NULL;
        if(next==NULL){
            printf("error\n");
        }
        else{
            printf("deleted value is %d\n",next->data);
            free(next);
        }
    }
    printf("\n\n");
}

int main()
{
    int ch;
    while(1){
        printf("\nenter your choice\n1 for creat\n2 for insert\n3 for delete\n");
        scanf("%d",&ch);
        switch(ch){

            case 1: creat();
                    print();
                    break;
            case 2: insert();
                    print();
                    break;
            case 3: delet();
                    print();
                    break;
            case 4: exit(0);
                    break;
            default: printf("your choice is wrong\n");
                     break;

        }
    }
}
