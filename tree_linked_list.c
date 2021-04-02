#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node * left, *right;
}NODE;

void pre_order(NODE *ptr)
{
    if(ptr)
    {
        printf("%d\t",ptr->info);
        pre_order(ptr->left);
        pre_order(ptr->right);
    }
}

void in_order(NODE * ptr)
{
    if(ptr)
    {
        in_order(ptr->left);
        printf("%d\t",ptr->info);
        in_order(ptr->right);
    }
}

void post_order(NODE * ptr)
{
    if(ptr!=NULL)
    {
        post_order(ptr->left);
        post_order(ptr->right);
        printf("%d\t",ptr->info);
    }
}


void creat_tree(NODE *ptr)
{
    NODE *leftnode,*rightnode;
    int item;
    char ch;
    if(ptr){

        printf("enter the element\n");
        scanf("%d",&ptr->info);
        printf("Do you want to add the right child of the node %d\n",ptr->info);

        ch=getche();
        if(ch=='y' || ch=='Y'){
            rightnode=(NODE*)malloc(sizeof(NODE));
            ptr->right=rightnode;
            creat_tree(rightnode);
        }
        else{
            ptr->right=NULL;
            creat_tree(NULL);
        }

        printf("Do ypu want to add the left child of the node %d\n",ptr->info);
        ch=getche();
        if(ch=='y' || ch == 'Y'){
            leftnode=(NODE*)malloc(sizeof(NODE));
            ptr->left=leftnode;
            creat_tree(leftnode);
        }
        else{
            ptr->left=NULL;
            creat_tree(NULL);
        }
    }
}

void display(NODE * ptr, int level)
{
    if(ptr!=NULL){
        display(ptr->right,level+1);
        for(int i=1;i<=level;i++)
            printf("\t");
        printf("%2d\n",ptr->info);
        display(ptr->left,level+1);
    }

}

int main()
{
    int a;
    NODE *root = NULL;
    while(1)
    {
        printf("Enter the choice\n1 for creat\n2 for display\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: root=(NODE*)malloc(sizeof(NODE));
                    creat_tree(root);
                    break;
            case 2: printf("dosplay the tree\n\n\n");
                    display(root,1);
                    break;
            case 3: printf("pre prder\n\n");
                    pre_order(root);
                    break;
            case 4: printf("in order\n\n");
                    in_order(root);
                    break;
            case 5: printf("post order\n\n");
                    post_order(root);
                    break;

            default: printf("type again\n");
                     break;


        }
    }
}
