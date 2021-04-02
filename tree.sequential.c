#include<stdio.h>
#include<math.h>
void father(int a[],int size);
void child(int a[], int size);
int main()
{
    int a[100],i,flag=0,d,size,w;
    printf("enter the depth of the level\n");
    scanf("%d",&d);
    size=pow(2,d+1)-1;
    printf("the maximax size of the tree is %d\nEnter the the tree by list\n",size);
    for(i=1;i<=size;i++)
        scanf("%d",&a[i]);
    printf("the list is\n");
    for(i=1;i<=size;i++)
        printf("%d\n",a[i]);
    while(1){
        printf("Enter your choice, 1 for find father, 2 for chaild\n");
        scanf("%d",&w);
        switch(w)
        {
            case 1: father(a,size);
                    break;
            case 2: child(a,size);
                    break;

        }
    }
}

void father(int a[],int size)
{
    int k=1,b,flag=0;
    printf("Enter the tree node");
    scanf("%d",&b);
    do{
        if(b==a[k]){
            flag=1;
            printf("the father of the node %d is %d\n",a[k],a[k/2]);
        }
        else if(b==a[k*2]){
            flag=1;
            printf("the father of the node %d is %d\n",a[k*2],a[k]);
        }
        else if(b==a[k*2+1]){
            flag=1;
            printf("the father of the node %d is %d\n",a[k*2+1],a[k]);
        }
        k++;
    }
    while(k<=size/2 && !flag);

    if(flag==1)
        printf("successfull\n");
    else
        printf("unsuccessfull\n");
}

void child(int a[], int size)
{
    int k=1,b,flag=0;
    printf("enter the element\n");
    scanf("%d",&b);
    do{
        if(b==a[k]){
            flag=1;
            printf("the chid of the %d is %d\t%d\n",a[k],a[k*2],a[k*2+1]);
        }
        k++;
    }
    while(k<=size && !flag);
    if(flag==0)
        printf("unsuccessfull\n");
    else
        printf("successfull\n");

}








