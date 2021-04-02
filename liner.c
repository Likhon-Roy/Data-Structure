#include<stdio.h>
int main()
{
    int ary[40],t,i,j,middle,first,last,k,key,n;
    scanf("%d",&t);
    for(int x=1;x<=t;x++){
    printf("enter the element num\n");
    scanf("%d",&n);
    printf("enter the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&ary[i]);
    }
    printf("enter the num which one you want to find\n");
    scanf("%d",&key);
//    prntf
    first=0;
    last=n-1;
    j=lsearch(n,ary,key,first,last);
    printf("the posttion is %d",j);
    /*
    middle=(first+last)/2;

    while(0<n){
        if(ary[middle]==key){
            printf("the element is in %d\n",middle+1);
            break;
        }
        else if(ary[middle]>key){
            last=middle-1;
        }
        else if(ary[middle]<key){
            first=middle+1;
        }

         middle=(first+last)/2;
         n--;

    }
    printf("first %d, last %d\n",first,last);
    if(first>last)
        printf("not found");*/

    }
}

int lsearch(int n, int ary[40], int key, int first, int last)
{
    int middle;
    /*
    first=0;
    last=n-1;*/
    middle=(first+last)/2;
    if(ary[middle]==key)
        return middle+1;
    else if(ary[middle]<key)
        first=middle+1;
    else if(ary[middle]>key)
        last=middle-1;
    return lsearch(n-1,ary,key,first,last);
}
