#include<stdio.h>
int main()
{
    int s=0,A[10][10],S[10][10],T[10][10],i,j,k,count=0,r,c;
    printf("enter the row and column num\n");
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r ;i++){
        for(j=0;j<c;j++){
            if(A[i][j]!=0){

                T[s][0]=j;
                T[s][1]=i;
                T[s][2]=A[i][j];
                S[s][0]=i;
                S[s][1]=j;
                S[s][2]=A[i][j];
                s++;
            }
        }
    }

    printf("the result is\n");

    printf("\n");
    for(i=0;i<s;i++){
        for(j=0;j<3;j++){
            printf("%d\t",T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<s;i++){
        for(j=0;j<3;j++){
            printf("%d\t",S[i][j]);
        }
        printf("\n");
    }
}
