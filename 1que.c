#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct luggage
{
    char name[20];
    char sor[20];
    char des[20];
    int id;
    float weight;
    struct luggage *next;
};

 typedef struct luggage *NODE;




 NODE getnode()

{

NODE newNode=(NODE)malloc(sizeof(struct luggage));

if(newNode==NULL)

{

printf("Not created\n");

exit(0);

}

  printf("Enter passenger_name  source  destination  luggage_id  weight \n");

  scanf("%s%s%s%d%f",newNode->name,newNode->sor,newNode->des,&newNode->id,&newNode->weight);

  newNode->next = newNode;

return newNode;

}
void display_list(NODE head)

{

NODE cur;

if(head==NULL)

{

   printf("Empty List\n");

   return NULL;

}

printf("luggage lists are\n");

cur = head;

 printf(" passenger_name  source  destination  luggage_id  weight \n");

while (cur->next!=head)

{


printf("%s\t%s\t%s\t%d\t%0.2f\n",cur->name,cur->sor,cur->des,cur->id,cur->weight);

   cur = cur->next;

}

printf("%s\t%s\t%s\t%d\t%0.2f\n",cur->name,cur->sor,cur->des,cur->id,cur->weight);


}
NODE insert_front( NODE head)

{

NODE newNode,cur;

newNode = getnode();

if(head == NULL)

{

    head=newNode;

  		return head;

}

cur = head;

while (cur->next!= head)

{

cur = cur->next;

}

cur->next = newNode;

newNode->next=head;

head=newNode;

    return head;

}

void search_by_id(NODE head)
{
    NODE cur=head;
    int flag=0;
    int s_id;
    printf("enter luggage id to know details\n");
    scanf("%d",&s_id);

    if(head==NULL)
    {
        printf("list is empty\n");
    }

    while(cur->next!=head)
    {
        if(cur->id == s_id)
        {
            flag=1;
            printf("%s\t%s\t%s\t%d\t%0.2f\n",cur->name,cur->sor,cur->des,cur->id,cur->weight);


        }
        cur=cur->next;
    }
if(cur->id == s_id)
        {
            flag=1;
            printf("%s\t%s\t%s\t%d\t%0.2f\n",cur->name,cur->sor,cur->des,cur->id,cur->weight);


        }

        if(flag==0)
        {
            printf("luggage id invalid\n");

        }
}

NODE delete_by_id(NODE head)
{   NODE prev=NULL;
 int flag=0;
    NODE cur=head;
    int d_id;
    printf("enter id to delte details\n");
    scanf("%d",&d_id);


    if(head==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }

    if(cur->next == head)
    {
        if(cur->id == d_id)
        {  flag=1;
         printf("deleted lagguage name is %s",cur->name);
         free(head);
         head=NULL;

        }

    }
    while(cur->next!=head)
    {
        if(cur->id == d_id)
        { flag=1;

             prev->next=cur->next;

            printf("Deleted luggage name: %s\n", cur->name);

            free(cur);
            break;


        }
        prev=cur;
        cur=cur->next;
    }
     if(cur->next == head)
    {
        if(cur->id == d_id)
        {  flag=1;
         printf("deleted lagguage name is %s",cur->name);
         free(head);
         head=NULL;

        }

    }

    return head;
}

void display_high_wt(NODE head)
{
    NODE cur=head;

    if(head==NULL)
    {
        printf("no node is present\n");
    }

    else
    {
        int high=cur->weight;
        cur=cur->next;

        while(cur->next!=head)
        {

            if(cur->weight > high)
                high=cur->weight;
            cur=cur->next;
        }
         if(cur->weight > high)
                {
                    high=cur->weight;
                }

                printf("highest weight is %d\n",high);


    NODE temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }

     printf("%s\t%s\t%s\t%d\t%0.2f\n",temp->name,temp->sor,temp->des,temp->id,temp->weight);
    }

}


int main()
{
    NODE head=NULL;


    int ch;

    while(1)
    {
        printf("1.insert front 2.display 3.search by id 4.delete using id 5.display highest weight\n");
        printf("enter choice\n");
        scanf("%d",&ch);


        switch(ch)
        {
        case 1:head=insert_front(head);
        break;
        case 2:  display_list(head);
        break;
        case 3: search_by_id(head);
        break;
        case 4: head=delete_by_id(head);
        break;
        case 5: display_high_wt(head);
        break;
        case 6: exit(0);

        default: printf("invalid choice\n");



        }
    }
    return 0;
}
