#include<stdio.h>
//#include<alloc.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
void display();
void creat();
int length();
void search(int item);
void insert(int item, int pos);
void insert_beg(int item);
void delet(int pos);
void insert_end(int item);
void delet_item(int item);

struct node
{
    int info;
    struct node *link;
};

typedef struct node Node;
Node *start=NULL;

int main()
{
    int a,item,pos;
    while(1){
        printf("\nEnter your choice:\n1 for creat:\n2 for display:\n3 for length:\n4 for search\n5 for insert\n6 for insert beg\n7 for insert end\n8 for delete\n");

        scanf("%d",&a);
        switch(a)
        {
            case 1: start=NULL;
                    creat();
                    break;
            case 2: display();
                    break;
            case 3: printf("the length of the linked list is %d\n",length());
                    break;
            case 4: printf("enter the search element\n");
                    scanf("%d",&item);
                    search(item);
                    break;
            case 5: printf("enter insert element and position:\n");
                    scanf("%d%d",&item,&pos);
                    if(pos==0 || pos>length()+1){
                        printf("invalid position\n");
                    }
                    else{
                        insert(item,pos);
                        printf("insart successfull");
                    }
                    break;
            case 6: printf("enter the item:\n");
                    scanf("%d",&item);
                    insert_beg(item);
                    break;
            case 7: printf("enter the element\n");
                    scanf("%d",&item);
                    insert_end(item);
                    break;
            case 8: printf("enter the element\n");
                    scanf("%d",&pos);
                    delet_item(pos);
                    break;
            case 20: exit(0);
            default: printf("choice error\n");
                     break;
            }
    }
}

void creat()
{
    int ch;
    int i=0;
    Node *currptr,*newnode;
    currptr=(Node*)malloc(sizeof(Node*));
    start=currptr;
    while(1){
        printf("enter the node: %d\n",i+1);
        scanf("%d",&currptr->info);
        printf("do tou wish to add one more node : (n/y)\n");
        ch=getche();
        //scanf("%d",&ch);

        if(toupper(ch)=='Y'){
            //printf("ch=%c\n",ch);
            newnode=(Node*)malloc(sizeof(Node));
            currptr->link=newnode;
            currptr=newnode;

        }
        else{
            currptr->link=NULL;
            break;
        }
        i++;
    }
}

void display()
{
    Node *temp;
    temp=start;
    while(temp!=NULL){
        printf("%d\t",temp->info);
        temp=temp->link;
    }

}

int length()
{
    Node *currptr;
    int lenth;
    currptr=start;
    for(lenth=0;currptr!=NULL;lenth++){
        currptr=currptr->link;
    }
    return lenth;
}

void search(int item)
{
    Node *currptr;
    int i=0;
    currptr=start;
    while(currptr!=NULL){
        if(item==currptr->info){
            i++;
            printf("the item position is %d= %d\n",item,i);
            break;
            //exit(1);
        }
        else{
            currptr=currptr->link;
            i++;
        }

    }
    if(currptr==NULL){
            printf("the item could not find\n");
    }

}

void insert(int item, int pos)
{
    Node *currptr, *newnode;
    newnode=(Node*)malloc(sizeof(Node*));
    newnode->info=item;
    if(start==NULL){
        start=newnode;
        newnode->link=NULL;
    }
    else if(start!=NULL && pos==1){
        newnode->link=start;
        start=newnode;
    }
    else{
        currptr=start;

        for(int i=0;i<pos-2;i++){
            currptr=currptr->link;

        }
        newnode->link=currptr->link;
        currptr->link=newnode;

    }
}

void insert_beg(int item)
{
    Node *currptr,*newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->info=item;
    if(start==NULL){

        newnode->link=NULL;
        start=newnode;
    }
    else{
        newnode->link=start;
        start=newnode;
    }
}

void insert_end(int item)
{
    Node *newnode,*currptr;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->info=item;
    if(start==NULL){
        start=newnode;

    }
    else{
        currptr=start;
        while(currptr->link!=NULL){
            currptr=currptr->link;
        }
        currptr->link=newnode;
    }
    newnode->link=NULL;
}

void delet(int pos)
{
    Node *currptr,*prev;
    if(start==NULL){
        printf("there is no linked list\n");
    }
    else if(start->link==NULL && pos ==1){
        printf("the delete item is %d:\n",start->info);
        start=NULL;
    }
    else if(start->link!=NULL && pos ==1){
        printf("the delete item is %d:\n",start->info);
        start=start->link;
    }
    else{
        currptr=start;
        //prev=currptr;
        for(int i=0;i<=pos-2;i++){
            prev=currptr;
            currptr=currptr->link;
        }

        prev->link=currptr->link;
        printf("the delete element is %d:\n",currptr->info);
        free(currptr);
    }

}

void delet_item(int item)
{
    Node *currptr,*prevptr,*temp;
    if(start->info==item && start->link==NULL){
        printf("the delete item is: %d\n",start->info);
        currptr=start;
        start=NULL;
        free(currptr);
    }
    else if(start->info==item && start->link!=NULL){
        currptr=start;
        start=start->link;
        printf("the delete item is: %d\n",start->info);
        free(currptr);
    }
    else if(start==NULL){
        printf("there is no linked list\n");

    }
    else{
        currptr=start;
        prevptr=NULL;
        for(int i=1;i<length()-1;i++){

            if(currptr->info==item && (currptr!=NULL)){
                prevptr->link=currptr->link;
                //temp=currptr;
                printf("the delete item is %d\n",currptr->info);
                //free(temp);
            }
            else if(currptr->link==NULL){
                break;
            }
            prevptr=currptr;
            currptr=currptr->link;

        }
    }

}


















