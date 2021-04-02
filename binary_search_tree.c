#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *left,*right;
};

typedef struct node NODE;

NODE *root=NULL;

void creat_tree(int item)
{
    NODE *currptr,*newnode,*ptr;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->info=item;
    if(root==NULL)
        root=newnode;
    else{
        currptr=root;
        while(currptr!=NULL){
            ptr=currptr;
            currptr=(item<currptr->info)? currptr->left : currptr->right;
        }
        if(ptr->info<item)
            ptr->right=newnode;
        else
            ptr->left=newnode;
    }
}

void display_tree(NODE *ptr, int level)
{
    if(ptr!=NULL)
    {
        display_tree(ptr->right,level+1);
        for(int i=1;i<=level;i++)
            printf("\t");
        printf("%d\n",ptr->info);
        display_tree(ptr->left,level+1);
    }
}

NODE *search_tree(NODE * ptr,int item)
{
    if(ptr==NULL)
        return NULL;
    else if(ptr->info==item)
        return ptr;
    else if(ptr->info<item)
        search_tree(ptr->right,item);
    else if(ptr->info>item)
        search_tree(ptr->left,item);
}


NODE *parent_search(NODE *ptr,int item)
{
    if(ptr==NULL)
        return NULL;
    else if(ptr->left->info==item || ptr->right->info==item)
        return ptr;
    else if(item<ptr->info)
        parent_search(ptr->left,item);
    else if(item>ptr->info)
        parent_search(ptr->right,item);
}

void delete_tree(int item)
{
    NODE *parent,*ptr;
    if(root==NULL)
        printf("The tree is empty\n");
    ptr=search_tree(root,item);
    if(ptr==NULL)
        printf("item not found\n");
    if(ptr->left==NULL && ptr->right==NULL){
        parent=parent_search(root,item);
        if(parent->left==ptr)
            parent->left=NULL;
        else if(parent->right==ptr)
            parent->right=NULL;
    }


    else if(ptr->left!=NULL || ptr->right!=NULL){
        parent=parent_search(root,item);
        if(parent->left==ptr){
            if(ptr->left!=NULL)
                parent->left=ptr->left;
            else
                parent->left=ptr->right;
        }
        else if(parent->right==ptr){
            if(ptr->left!=NULL)
                parent->right=ptr->left;
            else
                parent->right=ptr->right;
        }
    }
    else
        printf("the item could not be deleted\n");
}

NODE *smallest(NODE *ptr,int item)
{
    NODE *currptr=ptr;
    while(currptr->left!=NULL)
        currptr=currptr->left;
    return currptr;
}

NODE * minimum(NODE *ptr)
{
    while(ptr->left!=NULL)
    {
        ptr=ptr->left;
    }
    return ptr;
}

NODE *delete_all(NODE *ptr,int item)
{
    if(ptr==NULL)
        return NULL;
    if(ptr->info>item)
        ptr->left=delete_all(ptr->left,item);
    else if(ptr->info<item)
        ptr->right=delete_all(ptr->right,item);
    else{
        if(ptr->left==NULL){
            NODE *temp=ptr->right;
            free(ptr);
            return temp;
        }
        else if(ptr->right==NULL){
            NODE *temp=ptr->left;
            free(ptr);
            return temp;
        }
        else{
            NODE *temp=minimum(ptr->right);
            ptr->info=temp->info;
            ptr->right=delete_all(ptr->right,temp->info);
        }
    }
    return ptr;
}









int main()
{
    NODE *temp;
    int item,a;
    while(1)
    {
        printf("enter your choice\n1 for creat\n2 for search item\n3 for delete\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: printf("enter the item\n");
                    scanf("%d",&item);
                    creat_tree(item);
                    break;
            case 2: printf("enter the searching item\n");
                    scanf("%d",&item);
                    if(search_tree(root,item)==NULL){
                        printf("Item is not found\n");
                    }
                    else
                        printf("Item is found\n");
                    break;
            case 3: printf("enter the delete item\n");
                    scanf("%d",&item);
                    delete_tree(item);
                    break;
            case 4: printf("display the tree\n\n\n");
                    display_tree(root,1);
                    break;
            case 5: printf("enter the item for searching that parent\n");
                    scanf("%d",&item);
                    temp=parent_search(root,item);
                    if(temp==NULL)
                        printf("the item is not there\n");
                    else
                        printf("the parent of the item is %d\n",temp->info);
                    break;

            case 6: printf("enter the item for delete\n");
                    scanf("%d",&item);
                    delete_all(root,item);
                    break;
        }
    }
}
