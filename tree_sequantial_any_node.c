#include<stdio.h>
#include<math.h>
#include<conio.h>
int a[100],size;

void creat_tree(int j)
{
    int item;
    char ch;
    if(j!=0 && j<=size){
        printf("Entered the element\n");
        scanf("%d",&item);
        a[j]=item;
        printf("Do you want to %d add left element\n",j*2);
        ch=getche();
        if(ch=='y' || ch=='Y'){
            creat_tree(j*2);

        }
        else{
            creat_tree(0);
        }

        printf("Do you want to %d add right element\n",j*2+1);
        ch=getche();
        if(ch=='y' || ch=='Y'){
            creat_tree(j*2+1);
        }
        else{
            creat_tree(0);
        }
    }
}

int main()
{ i
    int b,i;
    printf("enter the level\n");
    scanf("%d",&b);
    size=pow(2,b+1)-1;
    printf("The size of the level is %d\n",size);
    for(i=1;i<=size;i++)
        a[i]=-1;
    creat_tree(1);
    for(i=1;i<=size;i++)
        printf("%d\n",a[i]);

}
