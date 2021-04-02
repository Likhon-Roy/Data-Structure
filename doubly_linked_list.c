#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<malloc.h>
void creat();
void display();
int length();
void delet_beg();
void delet_end();
void delet_pos(int pos);
void insert_beg(int item);
void insert_end(int item);
void insert(int item, int pos);

typedef struct node Node;

struct node
{
    int info;
    Node *back;
    Node *forw;
};

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
                    //printf("length\n");

                    break;

            /*case 4: printf("enter the search element\n");
                    scanf("%d",&item);
                    search(item);
                    break;*/
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
            case 8: delet_beg();
                    printf("delete successfull\n");
                    break;
            case 9: delet_end();
                    printf("delete successfull\n");
                    break;
            case 10: printf("enter the position\n");
                    scanf("%d",&pos);
                    delet_pos(pos);
                    break;
            /*case 11: printf("enter the item\n");
                     scanf("%d",&item);
                     delet_item(item);
                     break;*/
            case 20: exit(0);
            default: printf("choice error\n");
                     break;
            }
    }
}

void creat()
{
    char ch;
    Node *currptr,*newnode;
    currptr=(Node*)malloc(sizeof(Node));
    currptr->back=NULL;
    currptr->forw=NULL;
    start=currptr;
    while(1){
        printf("enter the element\n");
        scanf("%d",&currptr->info);
        printf("do you want to add one more element\n");
        ch=getch();
        if(toupper(ch)=='Y'){
            newnode=(Node*)malloc(sizeof(Node));
            currptr->forw=newnode;
            newnode->back=currptr;
            currptr=newnode;
        }
        else{
            currptr->forw=NULL;
            break;
        }
    }


}


void display()
{
    if(start==NULL){
        printf("no element\n");
    }
    else{
    Node *currptr;
    currptr=start;
    while(currptr!=NULL){
        printf("%d\t",currptr->info);
        currptr=currptr->forw;
    }
    }
}

int length()
{
    int i;
    Node *currptr;
    currptr=start;
    for(i=1;currptr->forw!=NULL;i++){
        currptr=currptr->forw;
    }
    return i;

}


void delet_beg()
{
    Node *currptr=start;
    if(start==NULL){
        printf("there is no linked list\n");

    }
    else if(start->forw==NULL){
        printf("the deleted item is %d\n",start->info);
        start=NULL;

        free(start);
    }
    else{
        printf("the deleted item is %d\n",start->info);
        start=currptr->forw;
        start->back=NULL;

        free(currptr);
    }

}

void delet_end()
{
    Node *currptr=start;
    if(start==NULL){
        printf("no element is there\n");
    }
    else if(start->forw==NULL){
        printf("the deleted item is %d\n",start->info);
        start=NULL;
        free(start);
    }
    else{
        while(currptr->forw!=NULL){
            currptr=currptr->forw;
        }
        printf("the deleted item is %d\n",currptr->info);
        currptr->back->forw=NULL;
        free(currptr);
    }
}

void delet_pos(int pos)
{
    int i;
    Node *currptr=start;
    if(pos==1){
        delet_beg();
    }
    else if(pos==length()){
        delet_end();
    }
    else{
        for(i=1;i<pos;i++){
            currptr=currptr->forw;
        }
        /*prevptr=currptr->back;
        next=currptr->forw;
        prevptr->forw=next;
        next->back=prevptr;*/
        printf("the deleted item is %d\n",currptr->info);
        currptr->back->forw=currptr->forw;
        currptr->forw->back=currptr->back;
        free(currptr);
    }
}

void insert_beg(int item)
{
    Node *newnode;
    if(start==NULL){
        start=(Node*)malloc(sizeof(Node));
        start->info=item;
        start->back=NULL;
        start->forw=NULL;
    }
    else{
        newnode=(Node*)malloc(sizeof(Node));
        newnode->info=item;
        newnode->back=NULL;
        newnode->forw=start;
        start->back=newnode;
        start=newnode;
    }
}

void insert_end(int item)
{
    Node *currptr=start,*newnode;
    if(start==NULL){
        start=(Node*)malloc(sizeof(Node));
        start->info=item;
        start->back=NULL;
        start->forw=NULL;
    }
    else{

        while(currptr->forw!=NULL){
            currptr=currptr->forw;
        }
        newnode=(Node*)malloc(sizeof(Node));
        newnode->info=item;
        currptr->forw=newnode;
        newnode->back=currptr;
        newnode->forw=NULL;
    }

}


void insert(int item, int pos)
{

    if(pos==1){
        insert_beg(item);
    }
    else if(pos==length()+1){
        insert_end(item);
    }
    else{
        Node *currptr, *newnode;
        currptr=start;
        for(int i=1;i<pos-1;i++){
            currptr=currptr->forw;
        }
        newnode=(Node*)malloc(sizeof(Node));
        newnode->info=item;

        currptr->forw->back=newnode;
        newnode->forw=currptr->forw;


        currptr->forw=newnode;
        newnode->back=currptr;
    }
}













