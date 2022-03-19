#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
    int id;
    char name[10];
};
typedef struct employee e;
int read(int n,e a[]);
int print(int n,e a[]);
int main()
{
    e a[10];
    int n;
    printf("enter the no. of employee");
    scanf("%d",&n);
    read( n,a);
    print( n,a);
}
int read(int n,e a[])
{
   int i;
   for(i=0;i<n;i++)
   {
       printf("enter the name id and name of employee");
       scanf("%d %s",&a[i].id,a[i].name);
   }
}
int print(int n,e a[])
{
   int j;
   for(j=0;j<n;j++)
   {
       printf("%d %s",a[j].id,a[j].name);
   }
}


