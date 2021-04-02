#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 4

struct queue
{
    int data[max+1];
    int front, rear;
};
typedef struct queue QUU;

void qinsert(QUU * qu)
{
    int item;
    if((qu->rear+1)%(max+1)==qu->front)
        printf("The queue is full\n");
    else{

        printf("enter the item\n");
        scanf("%d",&item);
        qu->data[qu->rear]=item;
        qu->rear=((qu->rear+1)%(max+1));
    }
}

void qdelete(QUU * qd)
{
    int i,sum,j;
    if(qd->front==qd->rear)
        printf("Queue is empty\n");
    else{
        sum=qd->data[qd->front];
        i=j=qd->front;
        for(i;i!=qd->rear-1;i=((i+1)%(max+1))){
            if(sum>(qd->data[i+1])){
                sum=qd->data[i+1];
                j=i+1;
            }
        }
        printf("Deleted item is %d\n",qd->data[j]);

        for(j;j!=qd->rear;j=((j+1)%(max+1))){
            qd->data[j]=qd->data[j+1];
        }
        //qd->rear=((qd->rear-1)%(max+1));
        qd->rear--;
    }
}

void display(QUU * qd)
{
    if(qd->front==qd->rear)
        printf("Empty\n");
    else{
        int i=qd->front;
        while(i!=qd->rear){
            printf("%d\n",qd->data[i]);
            i=(i+1)%(max+1);
        }
    }
}

int main()
{
    QUU my_q;
    int a,h,t,i;
    my_q.front=0;
    my_q.rear=0;
    while(a){
        printf("Enter your choice\n");
        scanf("%d",&a);
        switch(a){
            case 1: qinsert(&my_q);
                    break;
            case 2: qdelete(&my_q);
                    break;
            case 3: display(&my_q);
                    break;

                    /*h=my_q.front;
                    t=my_q.rear;
                    if(my_q.front==my_q.rear)
                        printf("empty");
                    else{
                        i=h;
                        while(i!=t){
                            printf("%d\n",my_q.data[i]);
                            i=(i+1)%(max+1);
                        }

                    }
                    break;*/

            case 4: exit(0);
                    break;
        }
    }
}























