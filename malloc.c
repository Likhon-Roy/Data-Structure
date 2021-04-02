#include<stdio.h>
#include<stdlib.h>
struct student
{
    int roll;
    char name;
};
int main()
{
    struct student* s;
    struct student k;
    k.roll=20;
    k.name='a';
    printf("%d",k.roll);
    printf("%c\n",k.name);
    s=(struct student*)malloc(sizeof(struct student));
    s->roll=10;
    s->name='k';
    printf("%d",s->roll);
    printf("%c",s->name);
}
