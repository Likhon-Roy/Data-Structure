#include<stdio.h>
#include<conio.h>
#define max 4

int queue[max],front=-1,rear=-1;

void qinsert(int item)
{
    if(((rear+1)%max)==front)
        printf("full\n");
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=item;
    }
    else{
        rear=(rear+1)%max;
        queue[rear]=item;
    }
}

void qdelete()
{
    if(front==-1&&rear==-1)
        printf("empty\n");
    else if(front==rear){
        printf("deleted %d\n",queue[front]);
        queue[front]=NULL;
        front=rear=-1;
    }
    else{
        printf("deleted %d\n",queue[front]);
        queue[front]=NULL;
        front=(front+1)%max;
    }
}

void disply()
{
    int i;
    if(front==-1&&rear==-1)
        printf("Kicu nei\n");
    else{
        i=front;
        while(i!=rear){
            printf("%d\n",queue[i]);
            i=(i+1)%(max);
        }
        printf("%d\n",queue[i]);
    }
}

int main()
{
    int a,item;
    while(1){
        printf("Enter your choice\n1 for insert\n2for delete\n3 for enpty or not\n4 for full or not\n5 for display\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: printf("Enter the element\n");
                    scanf("%d",&item);
                    qinsert(item);
                    break;
            case 2: qdelete();
                    break;
            //case 3: qempty();
              //      break;
            //case 4: qfull();
              //      break;
            case 5: disply();
                    break;
        }
    }
}
