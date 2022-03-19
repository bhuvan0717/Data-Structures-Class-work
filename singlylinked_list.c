#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct info
{

  int data;

  struct info *next;
};
typedef struct info *NODE;



NODE getnode();
NODE insert_end(NODE head);
void display(NODE head);




int main()
{
  NODE head=NULL;


  return 0;
}
  NODE getnode()
{
  NODE newn=(NODE)malloc(sizeof(struct info));
  if(newn==NULL)
{
  printf("memory not allocated\n");
  exit(0);
}
  printf("enter data \n");
  scanf(" %d",newn->data);
  newn->next=NULL;
  return newn;
}
 NODE insert_front(NODE head)
 {
     NODE cur=head;
     NODE newn=getnode();
     if (head==NULL)
     {
       head=newn;
     }
     else
     {
         newn next=head;
         head=newn;
     }
     return head;
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
    printf("list is empty\n");
  }
  else
  {
    while(cur!=NULL)
    {
      printf("%d\n",cur->data);
      cur=cur->next;
    }
  }
}
