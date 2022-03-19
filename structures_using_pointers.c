#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
    int id;
    char name[10];
};
typedef struct employee e;
int read();
int print();
int main()
{
    struct employee *Ptr;
    int n;
    printf("enter the no. of employee");
    scanf("%d",&n);
    Ptr=(e*)malloc(n*sizeof(struct employee));
    read(n,Ptr);
    print(n,Ptr);



    return 0;
}

int read(int n,struct employee *Ptr)
{
    int i;
    for(i=0;i<n;i++)
    {
         printf("Enter id, name: \n");
        scanf("%d %s",&(Ptr+i)->id,(Ptr+i)->name);
    }
}
int print(int n,struct employee *Ptr)
{
   int i;
   for(i=0;i<n;i++)
   {
       printf("%d %s",(Ptr+i)->id,(Ptr+i)->name);
   }
}

