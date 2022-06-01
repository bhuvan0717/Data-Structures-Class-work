#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct webseries
{
    char name[20],lang[10];
    int year,rating;
    float collection;
    struct webseries *next;
};
typedef struct webseries *NODE;

NODE getnode();
NODE insert_end(NODE head);
void display(NODE head);
void year(NODE head);
NODE reverse_list(NODE head);

int main()
{
    NODE head=NULL;
    int n;
    printf("ENTER NUMBER OF WEB-SERIES:\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            head=insert_end(head);
        }
    display(head);
    year(head);
    printf("REVERSED LIST:\n");
    head=reverse_list(head);
    display(head);
    return 0;
}

NODE getnode()
{
    NODE newn=(NODE)malloc(sizeof(struct webseries));
    if(newn==NULL)
    {
        printf("MEMORY NOT ALLOCATED\n");
        exit(0);
    }
    printf("ENTER SERIES NAME, LANGUAGE, YEAR, COLLECTION & RATING\n");
    scanf("%s %s %d %f %d",newn->name,newn->lang,&newn->year,&newn->collection,&newn->rating);
    newn->next=NULL;
    return newn;
}

NODE insert_end(NODE head)
    {
    NODE cur=head;
    NODE newn=getnode();
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newn;
    }
    return head;
}

void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%s %s %d %f %d\n",cur->name,cur->lang,cur->year,cur->collection,cur->rating);
            cur=cur->next;
        }
    }
}

void year(NODE head)
{
    int syear,flag=0,cnt=0;
    printf("ENTER YEAR OF WHICH DETAILS TO BE SEARCHED\n");
    scanf("%d",&syear);
    NODE cur=head;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        while(cur!=NULL)
        {
            if(cur->year==syear)
            {
                flag=1;
                printf("%s %s %d %f %d\n",cur->name,cur->lang,cur->year,cur->collection,cur->rating);
                cnt++;
            }
            cur=cur->next;
        }
            if(flag==0)
            {
                printf("WEB-SERIES NOT FOUND\n");
            }
    }
    printf("\nTOTAL NUMBER OF MOVIES IN YEAR %d ARE: %d\n\n",syear,cnt);
}

NODE reverse_list(NODE head)
{
	NODE nnode,cur,prev=NULL;
	cur=head;
	while(cur!=NULL)
	{
        nnode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nnode;
    }
return prev;
}
