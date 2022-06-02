#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct cell_phone
{
    char name[10];
    int price, memory;
}CP;
void read(FILE *,int);
void print(FILE *,int);
void main()
{
    int n;
    FILE *fp;
    printf("ENTER THE NO. OF PHONES:\n");
    scanf("%d",&n);
    read(fp,n);
    print(fp,n);
}
void read(FILE *fp, int n)
{
    int i;
    CP c1[10];
    fp=fopen("mobile.txt","w");
    printf("ENTER THE NAME, PRICE & MEMORY OF PHONE\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d",c1[i].name,&c1[i].price,&c1[i].memory);
        fprintf(fp,"%s\t%d\t%d\n",c1[i].name,c1[i].price,c1[i].memory);
    }
}
void print(FILE *fp,int n)
{
    int i=0;
    fp=fopen("mobile.txt","r");
    CP c2[10];
    while(!feof(fp))
    {
        fscanf(fp,"%s%d%d",c2[i].name,c2[i].price,c2[i].memory);
        i++;
    }
    printf("NAME\tPRICE\tMEMORY\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\n",c2[i].name,c2[i].price,c2[i].memory);
    }
}
