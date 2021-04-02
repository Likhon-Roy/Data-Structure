#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
void creat();
void display();
int length();
void insert(int item, int pos);
void insert_beg(int item);
void insert_end(int item);
void insert(int item, int pos);
void search(int item);
void delet_beg();
void delet_item(int item);
void delet_pos(int pos);
void delet_end();

struct node
{
    int info;
    struct node *link;
};

typedef struct node Node;

struct node *last=NULL;

int main()
{

    int a,item,pos;
    while(1){
        printf("\nEnter your choice:\n1 for creat:\n2 for display:\n3 for length:\n4 for search\n5 for insert\n6 for insert beg\n7 for insert end\n8 for delete\n");

        scanf("%d",&a);
        switch(a)
        {
            case 1: last=NULL;
                    creat();
                    break;
            case 2: display();
                    break;
            case 3: printf("the length of the linked list is %d\n",length());
                    //printf("length\n");

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
            case 11: printf("enter the item\n");
                     scanf("%d",&item);
                     delet_item(item);
                     break;
            case 20: exit(0);
            default: printf("choice error\n");
                     break;
            }
    }
}

void creat()
{
    char ch;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    last=newnode;
    newnode->link=last;
    while(1){
        printf("enter the element\n");
        scanf("%d",&last->info);
        printf("do you want to add mode node(y/n)\n");
        ch=getch();
        if(toupper(ch)=='Y'){
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->link=last->link;
            last->link=newnode;
            last=newnode;

        }
        else{
            break;
        }
    }
}

void display()
{
    if(last==NULL){
        printf("no element is there\n");
    }
    else{
    struct node *currptr;
    currptr=last->link;
    while(currptr!=last){
        printf("%d\t",currptr->info);
        currptr=currptr->link;
    }
    printf("%d\t",last->info);
    }
}


void insert_beg(int item)
{
    Node *currptr,*newnode;
    if(last==NULL){
        newnode=(Node*)malloc(sizeof(Node));
        newnode->info=item;
        last=newnode;
        newnode->link=last;
    }
    newnode=(Node*)malloc(sizeof(Node));
    newnode->info=item;
    newnode->link=last->link;
    last->link=newnode;
}

void insert_end(int item)
{
    Node *newnode;
    if(last==NULL){
        newnode=(Node*)malloc(sizeof(Node));
        newnode->info=item;
        last=newnode;
        newnode->link=last;
    }
    else{

    newnode=(Node*)malloc(sizeof(Node));
    newnode->info=item;
    newnode->link=last->link;
    last->link=newnode;
    last=newnode;
    }
}

int length()
{
    int i;
    Node *currptr;
    currptr=last->link;
    for(i=1;currptr!=last;i++){
        currptr=currptr->link;
    }
    //i++;
    return i;
}

void insert(int item, int pos)
{
    Node *newnode,*currptr,*temp;
    if(pos==1){
        insert_beg(item);
    }
    else if(length()+1==pos){
        insert_end(item);
    }
    else{

        currptr=last->link;
        //temp=NULL;
        for(int i=1;i<pos-1;i++){
            //temp=currptr;
            currptr=currptr->link;
        }
        newnode=(Node*)malloc(sizeof(Node));
        newnode->info=item;
        newnode->link=currptr->link;
        currptr->link=newnode;
    }
}

void search(int item)
{
    int i;
    Node *currptr;
    currptr=last->link;
    for(i=1; currptr!=last;i++){
        if(currptr->info==item){
            printf("the position of the item is:\t %d\n",i);
            break;
        }
        currptr=currptr->link;
    }
    if(last->info==item){
        printf("the position of the item is:\t %d\n",i);
    }
}

void delet_beg()
{
    Node *currptr;
    currptr=last->link;
    if(last==NULL){
        printf("there is no linked list\n");
    }

    else if(currptr==last){
        last=NULL;
        free(currptr);
        //printf("successfull\n");
    }
    else{
    //currptr=currptr->link;
    last->link=currptr->link;
    free(currptr);
    }
}

void delet_end()
{
    Node *currptr,*temp;
    currptr=last->link;
    if(last==NULL){
        printf("there is no element to delete");
    }
    else if(currptr==last){
        last=NULL;
        free(currptr);
        //printf("successfull\n");
    }
    else{
        //currptr=last->link;
        //prevptr=NULL;
        while(currptr->link!=last){
            //prevptr=currptr;
            currptr=currptr->link;
        }
        currptr->link=last->link;
        temp=last;
        last=currptr;
        free(temp);
    }
}

void delet_pos(int pos)
{
    Node *currptr,*prevptr;
    currptr=last->link;
    prevptr=NULL;
    if(pos==1){
        delet_beg();
    }
    else if(pos==length()){
        delet_end();
    }
    else{
        for(int i=1;i<pos;i++){
            prevptr=currptr;
            currptr=currptr->link;
        }
        prevptr->link=currptr->link;
        free(currptr);
    }

}


void delet_item(int item)
{
    Node *currptr,*prevptr;
    currptr=last->link;
    if(currptr->info==item){
        delet_beg();
    }
    else if(last->info==item){
        delet_end();
    }
    else{
        while(currptr->info!=item){
            prevptr=currptr;
            currptr=currptr->link;
        }
        prevptr->link=currptr->link;
        free(currptr);
    }
}



























