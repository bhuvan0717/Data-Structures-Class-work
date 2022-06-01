#include<stdio.h>
#include<string.h>
typedef struct player
{
    char name[20];
    int runs;
}BCR;
void read(BCR [],int);
void print(BCR [],int);
void select(BCR [],int);

int main()
{
    BCR p[10];
    int n;
    printf("ENTER THE NUMBER OF PLAYERS:\t");
    scanf("%d",&n);
    read(p,n);
    printf("\nPLAYER DETAILS:\n\n");
    print(p,n);
    select(p,n);
    return 0;
}
void read(BCR p[], int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d%s",&p[i].runs,p[i].name);
}
void select(BCR p[], int n)
{
    BCR p1[5];
    int i,j,temp;
    char temp1[20];
    for(i=1;i<n;i++)
        for(j=0;j<n-i;j++)
        {
            if(p[j].runs < p[j+1].runs)
            {
                temp = p[j].runs;
                p[j].runs=p[j+1].runs;
                p[j+1].runs=temp;
                strcpy(temp1, p[j].name);
                strcpy(p[j].name,p[j+1].name);
                strcpy(p[j+1].name,temp1);

            }
        }
    p1[0].runs = p[0].runs;
    strcpy(p1[0].name,p[0].name);
     p1[1].runs = p[1].runs;
    strcpy(p1[1].name,p[1].name);
     p1[2].runs = p[2].runs;
    strcpy(p1[2].name,p[2].name);
    p1[3].runs= p[n-1].runs;
    strcpy(p1[3].name,p[n-1].name);
    for(i=0;i<n;i++)
    {
        if(strcmp(p[i].name,"Rajat")==0)
        {
            p1[4].runs= p[i].runs;
           strcpy(p1[4].name,"Rajat");

        }
    }
    printf("SELECTED PLAYERS:\n");
   print(p1,5);
}

void print(BCR p[], int n)
{
    for(int i=0;i<n;i++)
        printf("NAME: %s\tRUNS:%d",p[i].name,p[i].runs);
}
