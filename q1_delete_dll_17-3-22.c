#include<stdio.h>
#include<stdlib.h>

struct riping
{
    int mango;
    struct riping *next;
    struct riping *prev;
};

typedef struct riping *NODE;

NODE getnewnode();
NODE insert_end(NODE head);
NODE delete_front(NODE head);

void display(NODE head);

int main()
{
    NODE head=NULL;
    int n;
    printf("Enter number of mangoes:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        head=insert_end(head);
    }
    delete_front(head);
    return 0;
}

NODE getnewnode()
{
    NODE newn=(NODE)malloc(sizeof(struct riping));
    if(newn==NULL)
    {

        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        scanf("%d",&newn->mango);

        newn->next=newn;
        newn->prev=newn;
    }
}

NODE insert_end(NODE head)
{
    NODE cur=NULL;
    NODE newn=getnewnode();
    if(head==NULL)
        head=newn;
    else
    {
        cur=head->prev;

        cur->next=newn;
        newn->prev=cur;

        newn->next=head;
        head->prev=newn;
    }
    return head;
}

NODE delete_front(NODE head)
{
    NODE temp=NULL,cur=NULL;
    if(head==NULL)
    {
        printf("CDLL mangoes list is empty\n");
    }
    else if(head->next==head)
    {
        printf("Mango fell: %d\n",head->mango);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head->prev;
        temp=head;
        head=head->next;
        head->prev=cur;
        cur->next=head;
        printf("Mango fell: %d\n",temp->mango);
        free(temp);
    }
    return head;
}
