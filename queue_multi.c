#include<stdio.h>
#include<conio.h>
#define N 4

//#define n=5

int queue[3][N+1];
int front[3]={0,0,0};
int rear[3]={0,0,0};

void qinsert()
{
    int pr,item;
    printf("Enter the priority\n");
    scanf("%d",&pr);
    pr=pr-1;
    if(pr<N && pr>=0){
        if((rear[pr]+1)%(N+1)==front[pr]){
            printf("the queue is full\n");
        }
        else{
            printf("Enter the element\n");
            scanf("%d",&item);
            queue[pr][rear[pr]]=item;
            rear[pr]=(rear[pr]+1)%(N+1);
        }
    }
    else
        printf("wrong\n");
    //return;
}

void qdelete()
{
    for(int i=0;i<3;i++){
        if(rear[i]==(front[i]))
            printf("empty list\n");
        else{
            printf("the delete item is %d\n",queue[i][front[i]]);
            front[i]=(front[i]+1)%(N+1);
            return;
        }
    }
}

void qdisplay()
{
    int i,j;
    for(i=0;i<3;i++){
        if(rear[i]==front[i])
            printf("empty priority %d\n",i+1);
        else{
            printf("for the priority %d\n",i+1);
            for(j=front[i];j!=rear[i];j=(j+1)%(N+1)){
                printf("%d\t",queue[i][j]);

            }
            printf("\n");
        }
    }
}

int main()
{
    int a,b;
    while(1)
    {
        printf("enter your choice\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: qinsert();
                    break;
            case 2: qdelete();
                    break;
            case 3: qdisplay();
                    break;
        }
    }
}
