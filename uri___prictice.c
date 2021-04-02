#include<stdio.h>
//#include<conio.h>
int main()
{
    char name[40];
    double sellers_salary,sold,percentage;
    scanf("%s",name);
    scanf("%lf%lf",&sellers_salary,&sold);
    percentage=(15*sold)/100;

    printf("TOTAL = R$ %.2lf\n",percentage+sellers_salary);

    return 0;
}
