#include<stdio.h>
#include<stdlib.h>

struct birthday
{
    int candle;
    struct birthday *next;
    struct birthday *prev;
};

typedef struct birthday *NODE;

NODE getnewnode();
NODE insert_end(NODE head);
void display(NODE head);


int main()
{
    NODE head=NULL;
    int n;
    printf("Enter n:\n");
    scanf("%d",&n);
    if(n>0){
    for(int i=0;i<n;i++)
    {
        head=insert_end(head);
    }

    }
    else{
        printf("Invalid input.\n");
    }
    display(head);
    return 0;
}

NODE getnewnode()
{
    NODE newn=(NODE)malloc(sizeof(struct birthday));
    if(newn==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        scanf("%d",&newn->candle);

        newn->next=newn;
        newn->prev=newn;
    }
    return newn;
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
void display(NODE head)
{
    NODE temp=NULL;
    if(head==NULL)
    {
        printf("Empty");
    }
    else{
        temp=head;
        do{
        printf("%d ",temp->candle);
            temp=temp->next;
        }while(temp!=head);
    }
    printf("\n");
}



