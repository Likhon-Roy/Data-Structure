#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right,*parent;
};

typedef struct node Node;

Node *creat_newnode(int item)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->parent=NULL;
    newnode->data=item;
    return newnode;
}

void add_left_node(Node *par,Node *child)
{
    par->left=child;
    if(child!=NULL)
        child->parent=par;
}


void add_right_node(Node *par,Node *child)
{
    par->right=child;
    if(child!=NULL)
        child->parent=par;
}

Node *insert_tree(Node *root, Node *node)
{
    Node *currptr,*ptr;
    if(root==NULL){
        root=node;
        return root;
    }
    currptr=root;
    while(currptr!=NULL){
        ptr=currptr;
        currptr=(currptr->data<node->data)?currptr->right:currptr->left;
    }
    if(ptr->data<node->data)
        add_right_node(ptr,node);
    else
        add_left_node(ptr,node);
    return root;
}

void displaying_node(Node *ptr,int level)
{
    if(ptr){
        displaying_node(ptr->right,level+1);
        for(int  i=0;i<level;i++)
            printf("\t");
        printf("%d\n",ptr->data);
        displaying_node(ptr->left,level+1);
    }
}

Node *search_item(Node *ptr,int item)
{
    if(ptr==NULL)
        return ptr;
    if(ptr->data<item)
        search_item(ptr->right,item);
    else if(ptr->data>item)
        search_item(ptr->left,item);
    else
        return ptr;
}

Node * succesor_node(Node *ptr)
{
    if(ptr->left!=NULL)
        return succesor_node(ptr->left);
    return ptr;
}

int main()
{
    int n,item;
    Node *node,*currptr,*root=NULL;
    printf("enter the number for the total element of the tree\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&item);

        node=creat_newnode(item);

        root=insert_tree(root,node);
    }

    printf("the tree is\n\n\n");
    displaying_node(root,1);


    printf("enter the number for search\n");
    scanf("%d",&item);
    currptr=search_item(root,item);
    if(currptr==NULL)
        printf("item is not found\n");
    else{
        printf("item is not found\n%d\n",currptr->data);
    }

    printf("enter the number for surccasor\n");
    scanf("%d",&item);
    currptr=search_item(root,item);
    currptr=succesor_node(currptr->right);
    if(currptr==NULL)
        printf("item is not found\n");
    else{
        printf("item is not found\n%d\n",currptr->data);
    }
}





















