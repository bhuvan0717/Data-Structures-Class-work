#include<stdio.h>
#include<stdlib.h>

struct birthday
{
    int height;
    struct birthday *next, *prev;
};
typedef struct birthday *NODE;
NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct birthday));
    if(newn==NULL)
    {
        printf("Memory is not allocated\n");
    }
    printf("Enter height\n");
    scanf("%d",&newn->height);
    newn->prev=newn;
    newn->next=newn;
    return newn;
}
NODE insert_end(NODE head)
{
    NODE temp,cur=head;
    temp=getnode();
    if(head==NULL)
    {
        head=temp;
         return head;
    }
    else
    {
      while(cur->next!=head)
      {
          cur=cur->next;
      }
      cur->next=temp;
      temp->prev=cur;
      temp->next=head;
      return head;
    }

}
NODE display_from_firsttolast(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
       cur=head;
       while(cur->next!=head)
       {
           printf("%d\t",cur->height);
           cur=cur->next;
       }
       printf("%d\t",cur->height);
       printf("\n");
    }
    return head;
}


int main()
{
    NODE head=NULL;
    int n,i;
    printf("Enter age\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       head=insert_end(head);
    }
    head=display_from_firsttolast(head);

    return 0;
}
