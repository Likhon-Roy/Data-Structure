#include<stdio.h>

int main()
{
    int n;
    int i;
    printf("enter the number for fibonacy");
    scanf("%d",&n);
    for(i=1;i<=n;i++){

        printf("%d\t",fibonacy(i));
    }

}

int fibonacy(int n)
{
    if(n==1 || n==0){
        return (0);
    }
    else if(n==2){
        return (1);
    }
    else{
        return(fibonacy(n-1)+fibonacy(n-2));
    }
}
