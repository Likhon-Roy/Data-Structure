#include<stdio.h>
#include<string.h>
int main()
{
    int x,T,i;
    char S[100],S2[100];
    scanf("%d",&T);
    for(int x=0;x<T;x++){
    scanf(" %[^\n]",&S);


    int j = strlen(S)-1;
    for(i=0;i<=j;i++){
        if(S[j]!=' '){
            S2[i]=S[j];
            j--;
        }
        else if(i>0){
            S2[i]='\0';
            printf("%s ",S2);
        }
    }
    /*if(i>0){
        S2[i]='\0';
        printf("%s\n",S2);
    }*/

    }

}
