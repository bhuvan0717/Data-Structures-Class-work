#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct d
{

    int id;
    struct d *next;
    struct d *link;
};

typedef struct d *NODE;

NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct d));
    if(newn==NULL)
    {
        printf("NOT CREATED");
        exit(0);
    }
    newn->next=NULL;
    return newn;
}

NODE read_details()
{
    NODE temp;
    temp=getnode();
    printf("ENTER ID:\n");
    scanf("%d",&temp->id);
    return temp;
}

NODE insert_end(NODE head)
{
    NODE newn=NULL, cur=NULL;
    newn = read_details();
    if(head == NULL)
    {
        return newn;
    }
    else
    {
        cur=head;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = newn;
    }
    return head;
}
void display(NODE head)
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
        printf("EMPLOYERS id");
        printf("head-> ");
        while(cur!=NULL)
        {
            printf("%d -> ", cur->id);
            cur=cur->next;
        }
        printf("NULL\n");
    }
}
NODE sort(NODE head)
{
    NODE ind,cur=head;
    int temp;
    while(cur!=NULL)
    {

        ind=cur->next;
        while(ind!=NULL)
        {
            if(cur->id>=ind->id)
            {
                temp=cur->id;
                cur->id=ind->id;
                ind->id=temp;
            }
            ind=ind->next;
        }
        cur=cur->next;
    }
    return head;
}
NODE merge(NODE head,NODE second)
{
    NODE cur;
    cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=second;
    return head;
}
NODE link(NODE head,NODE head1,NODE head2,NODE head3)
{
    NODE temp=head,cur;
    head->link=head1;
    head1->link=head2;
    head2->link=head3;
    head3->link=NULL;
  while(temp!=NULL)
  {
      printf("%d\t",cur->id);
       cur=temp;
       cur=cur->link;
       while(cur!=NULL)
       {
           printf("%d\t",cur->id);
           cur=cur->link;
       }
       printf("\n");
       temp=temp->next;

  }
  return head;


}
int main()
{
    NODE head=NULL,head1=NULL,head2=NULL,head3=NULL;
     int choice,cnt;
        printf("1 insert in 1st list ,2 insert in 2nd list, 3 insert in 3rd list ,4 insert in 4th list 5 display 1st list ,6 display 2nd list, 7 display 3rd list ,8 display 4th list,9 merge,10 sort");
        while(1)
        {
            printf("ENTER CHOICE:\t");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:head=insert_end(head);
                       break;
                case 2:head1=insert_end(head1);
                       break;
                 case 3:head2=insert_end(head2);
                       break;
                  case 4:head3=insert_end(head3);
                        break;
                  case 5:display(head);
                        break;
                  case 6:display(head1);
                        break;
                  case 7:display(head2);
                         break;
                  case 8:display(head3);
                         break;
                  case 9:head=merge(head,head1);
                        head1=NULL;
                        head=merge(head,head2);
                        head2=NULL;
                        head=merge(head,head3);
                        head3=NULL;
                        display(head);
                        break;
                 case 10:head=sort(head);
                         display(head);
                        break;
                case 11:head=link(head,head1,head2,head3);

                        break;

                default: printf("INVALID CHOICE\n");
            }
}
return 0;
}
