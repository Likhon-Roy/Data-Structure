#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define q_size 3

typedef struct
{
    int data[q_size+1];
    int head,tail;
}queue;

void enqueue(queue *q,int item)
{
    if((q->tail+1)%(q_size+1)==q->head)
        printf("The queue is full");
    else{
        q->data[q->tail]=item;
        q->tail=((q->tail+1)%(q_size+1));
    }
}

int dequeue(queue *q)
{
    int item;
    if(q->head==q->tail){
        printf("The list is empty\n");
        return -1;
    }
    else{
        item=q->data[q->head];
        q->head=((q->head+1)%(q_size+1));
        return item;
    }
}

/*void disply(queue * q)
{
    int i;
    if(q->head==q->tail)
        printf("Empty queue\n");
    else{
        for(i=q->head;i<=q->tail;i++){
            printf(q->data[i]);
        }
    }
}*/

int main()
{
    int dif,i,temp,j=0,h,t;
    int a,item;
    queue my_q;

    my_q.head=0;
    my_q.tail=0;

    while(1){
        printf("Enter your choice\n1 for insert\n2for delete\n3 for enpty or not\n4 for full or not\n5 for display\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: printf("Enter the element\n");
                    scanf("%d",&item);
                    enqueue(&my_q,item);
                    break;
            case 2: printf("the deleted item is %d\n",dequeue(&my_q));
                    break;
            //case 3: disply(&my_q);
                //    break;
            //case 4: qfull();
              //      break;
            case 5: h=my_q.head;
                    t=my_q.tail;
                    if(my_q.head==my_q.tail)
                        printf("empty");
                    else{
                        i=h;
                        while(i!=t){
                            printf("%d\n",my_q.data[i]);
                            i=(i+1)%(q_size+1);
                        }

                    }

                    break;
        }
        printf("\n\n\n\n");
    }

}










