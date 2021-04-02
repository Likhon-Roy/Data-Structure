#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int i;
    ptr=(int*)calloc(5,sizeof(int));
    if(ptr!=NULL){
        ptr[0]=10;
        *(ptr+1)=20;
        ptr[2]=30;
        ptr[3]=40;
        ptr[4]=50;
        for(i=0;i<7;i++){
            printf("%d\t",ptr[i]);
        }
        printf("\n");
        ptr=(int*)realloc(ptr,7*sizeof(int));
        *(ptr+5)=60;
        ptr[6]=70;
        for(i=0;i<7;i++){
            printf("%d\t",ptr[i]);
        }





        //printf("%d",ptr[2]);
    }
    printf("\n%d\n",ptr);
    free(ptr);
    printf("%d",ptr);
}
