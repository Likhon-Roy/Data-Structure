#include<stdio.h>
#include<string.h>
int main()
{
    int count[26],i,n,h=97,T;
    char str[40];
    scanf("%d",&T);
    for(int x=0;x<T;x++){
    printf("enter the number\n");
    scanf(" %[^\n]",&str);

    for(i=0;i<26;i++){
        count[i]=0;
    }

    for(i=0;i<strlen(str);i++){
        if(str[i]>='a'&&'z'>=str[i]){
            count[str[i]-'a']=count[str[i]-'a']+1;
        }
    }
    for(i=0;i<26;i++){
        if(count[i]!=0){
            printf("%c = %d\n",'a'+i,count[i]);
        }
    }

    }

}
