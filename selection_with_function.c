#include<stdio.h>
int main()
{
    int n,a[100],i,temp,loc;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        loc=selection(a,i,n);
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

}

int selection(int a[], int i, int n)
{
    int min,j,loc;
    min=a[i];
    loc=i;
    for(j=i+1;j<=n-1;j++){
        if(min>a[j]){
            min=a[j];
            loc=j;
        }
    }
    return (loc);
}
