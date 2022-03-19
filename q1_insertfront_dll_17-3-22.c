//Almost all SLL

#include<stdio.h>
#include<stdlib.h>

struct employee
{

    int id;
    struct employee *next;
    struct employee *prev;
};

typedef struct employee *NODE;

NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct employee));
    if(newn==NULL)
    {
        printf("NOT CREATED");
        exit(0);
    }
    newn->next=NULL;
    newn->prev=NULL;
    return newn;
}

NODE read_details()
{
    NODE temp;
    temp=getnode();
    printf("ENTER EMP ID:\n");
    scanf("%d",&temp->id);
    return temp;
}


NODE insert_front(NODE head)
{
    NODE newn;
    newn=read_details();
    newn->next=NULL;
    if(head==NULL)
        return newn;
    newn->next=head;
    head=newn;
    return head;
}

void display_list(NODE head)
{
    NODE cur=NULL;
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
        exit(0);
    }
    else
    {
        cur=head;
        printf("DETAILS\n");
        printf("EMP ID:\n");

        while(cur!=NULL)
        {
            printf("%d  ", cur->id);
            cur=cur->next;
        }
        printf("NULL\n");
    }
}










int main()
{
    NODE head=NULL,second=NULL,sechead=NULL;

    int n;
    printf("Enter number of emp:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        head=insert_front(head);
    }
    display_list(head);



        return 0;
}
