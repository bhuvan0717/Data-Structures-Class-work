#include<stdio.h>
typedef struct cell_phone
{
    char name[10];
    int price,memory;
}CP;
void read(CP *,int);
void print(CP *,int);
void main()
{
    CP c1[10],*c;
    int n;
    c=&c1[0];
    printf("ENTER THE NO. OF DEVICES\n");
    scanf("%d",&n);
    read(c,n);
    print(c,n);
}
void read(CP *c, int n)
{
    int i;
    printf("ENTER THE NAME, PRICE & MEMORY OF PHONE\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d",(c+i)->name,&(c+i)->price,&(c+i)->memory);
    }
}
void print(CP *c,int n)
{
    int i;
    printf("NAME\tPRICE\tMEMORY\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\n",(c+i)->name,(c+i)->price,(c+i)->memory);
    }
}
