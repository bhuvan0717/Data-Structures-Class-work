#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct data
{
   int num;
   struct data *next;
};
typedef struct data *NODE;
NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct data));
    if(newn==NULL)
    {
        printf("Not created\n");
        exit(0);
    }
    newn->next = NULL;
    return newn;
}
NODE read_details()
{
    NODE temp;
    temp = getnode();
    scanf("%d",&temp->num);
    return temp;
}
NODE insert_end (NODE head)
{
    NODE new, cur;
    new = read_details();
    new ->next = NULL;
            if(head==NULL)
              return new;
    cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur -> next = new;
        return head;
}
NODE rotnode(NODE head)
{

    NODE cur, prev;
    int temp;
    cur = head;
    prev=cur->next;
    while (cur->next!=NULL)
    {
        temp=cur->num;
        cur->num=prev->num;
        prev->num=temp;
        prev=prev->next;
        cur=cur->next;
    }
    return head;
}
NODE display (NODE head)
{
    NODE cur;
    if(head==NULL)
    {
       printf("Empty List\n");
       return NULL;
    }
    printf("elements are\n");
    cur = head;

    while (cur != NULL)
    {
       printf("%d\n",cur->num);
       cur = cur ->next;
    }
}

int main()
{
   NODE head=NULL;
   int n,i;
   printf("enter number of nodes to be created");
   scanf("%d", &n);
   for ( i = 0; i < n; i++)
   {
       head=insert_end(head);
   }
   display(head);
   int k;
    printf("enter number of times to rotate\n");
    scanf("%d",&k);
    for ( i = 0; i <k; i++)
    {
        head=rotnode(head);
    }


   display(head);
   return 0;
}
