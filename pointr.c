#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    int i1;
    double d2;
    char ch[50];
    scanf("%d",&i1);
    scanf("%lf",&d2);
    scanf(" %[^\n]",&ch);

    strcpy(s,ch);

    printf("%d\n",i+i1);
    printf("%lf\n",d2+d);
    printf("%s\n",s);


    return 0;
}
