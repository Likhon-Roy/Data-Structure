#include<stdio.h>
int main()
{
    int ary[40],lok=0,n,i,j,temp,a,min;
    printf("enter the elemt\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&ary[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",ary[i]);
    }

    for(i=0;i<n;i++){
        min=ary[i];
        lok=i;
        for(j=i+1;j<=n-1;j++){
            if(min>ary[j]){
                min=ary[j];
                lok=j;
            }

        }
        temp=ary[i];
        ary[i]=ary[lok];
        ary[lok]=temp;

    }

    printf("the output is\n");
    for(i=0;i<n;i++){
        printf("%d  ",ary[i]);
    }

}
