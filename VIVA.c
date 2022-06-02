
//Circular doubly linked list for storing the students grades
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int ripe;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

//function prototypes
NODE getnewnode();
NODE insert_front_cdll(NODE head);
NODE insert_end_cdll(NODE head);
void display_cdll(NODE head);
void display_Lasttofirst_cdll(NODE head);

NODE delete_front_cdll(NODE head);
NODE delete_end_cdll(NODE head);
NODE insert_before_cdll(NODE head, char keygrade1);
NODE insert_after_cdll(NODE head, char keygrade);
NODE delete_grade_cdll(NODE head, char delgrade);

int main()
{
    int i,n;
    char keygrade,keygrade1,delgrade;
    NODE head=NULL;
    int choice;

    for(;;)
    {

        printf("\n1.insert front\n2.insert end\n3.display\n4.insert_after_cdll\n5.Insert_before_cdll\n6.Displaybackward\n7.delete_front\n8.delete_end\n9.deletegrade\n10.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head= insert_front_cdll(head);
                    break;
            case 2: head= insert_end_cdll(head);
                    break;
            case 3: display_cdll(head);
            break;
            case 4: printf("\nInsert after CDLL\n");
                    printf("Enter the grade after which to add the newnode?\n");
                    scanf(" %c", &keygrade);
                    head= insert_after_cdll(head,keygrade);
                    break;
            case 5: printf("\nInsert before CDLL\n");
                    printf("Enter the grade before which to add the newnode?\n");
                    scanf(" %c", &keygrade1);
                    head = insert_before_cdll(head, keygrade1);
                    break;
            case 6: display_Lasttofirst_cdll(head);
                    break;
            case 7:head=delete_front_cdll(head);
                    break;
            case 8: head=delete_end_cdll(head);
                    break;
            case 9: printf("\nDelete grade CDLL\n");
                    printf("Enter the grade to delete?\n");
                    scanf(" %c", &delgrade);
                    head=delete_grade_cdll(head,delgrade);
            break;
            default:exit(0);

        }
    }
     return 0;
}

NODE getnewnode()
{
    NODE newn=(NODE)malloc(sizeof(struct node));
    if(newn==NULL)
    {

        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        printf("Enter grade:");
        scanf(" %c",&newn->grade);

        newn->next=newn;
        newn->prev=newn;
    }
}

NODE insert_front_cdll(NODE head)
{
    NODE cur=NULL;
    NODE newn=getnewnode();
    if(head==NULL)
        head=newn;
    else
    {
        cur=head->prev;

        newn->next=head;
        head->prev=newn;

        cur->next=newn;
        newn->prev=cur;

        head=newn;
    }
    return head;
}

NODE insert_end_cdll(NODE head)
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

void display_cdll(NODE head)
{

    NODE cur=head;

    if(head==NULL)
        printf("CDLL grades list is empty\n");
    else
    {
        do
        {
            printf("%c\t",cur->grade);
            cur=cur->next;
        }while(cur!=head);
    }
}

NODE insert_after_cdll(NODE head, char keygrade2)
{
    NODE newn = getnewnode();
    NODE back=NULL, cur=head;
    while(cur->next != NULL)
    {
        if(cur->grade == keygrade2)//one node
            break;
         else
         {
             back = cur;
             cur = cur->next;
         }
    }
    //one time shift.
    back = cur;
    cur = cur->next;

    if(cur == head && back->grade != keygrade2)
        printf("Key grade not present in the CDLL\n");
    else
    {
        back->next = newn;
        newn->prev = back;

        newn->next = cur;
        cur->prev = newn;
    }
    return head;
}

NODE insert_before_cdll(NODE head, char keygrade)
{
    NODE newn = getnewnode();
    NODE back=NULL, cur=head;
    if(head->grade == keygrade)//INSERT FRONT at the beginning of the list
    {
        back = head->prev;

        back->next = newn;
        newn->prev = back;

        newn->next = head;
        head->prev = newn;

        head = newn;
    }
    while(cur->next != head)
    {
        if(cur->grade == keygrade)
            break;
        else
        {
            back= cur;
            cur = cur->next;
        }
    }
    if(cur->next == head && cur->grade != keygrade)
        printf("Key grade node not present in the CDLL\n");
    else
    {
        back->next = newn;
        newn->prev = back;

        newn->next = cur;
        cur->prev = newn;
    }
    return head;
}



void display_Lasttofirst_cdll(NODE head)
{

    NODE cur=head;
    if(head==NULL)
        printf("CDLL grades list is empty\n");
    else
    {
        cur=head->prev;
        do
        {

            printf("%c\t",cur->grade);
            cur=cur->prev;
        }while(cur!=head);
        printf("%c\t",cur->grade);
    }
}

NODE delete_front_cdll(NODE head)
{
    NODE del=NULL,cur=NULL;
    if(head==NULL)
    {
        printf("CDLL grades list is empty\n");
    }
    else if(head->next==head)
    {
        printf("Deleted grade %c\n",head->grade);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head->prev;
        del=head;
        head=head->next;
        cur->next=head;
        head->prev=cur;
        printf("Deleted grade %c\n",del->grade);
        free(del);
    }
    return head;
}

NODE delete_end_cdll(NODE head)
{
     NODE back=NULL,cur=NULL;
    if(head==NULL)
    {
        printf("CDLL grades list is empty\n");
    }
    else if(head->next==head)
    {
        printf("Deleted grade %c\n",head->grade);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head->prev;
        back=cur->prev;
        back->next=head;
        head->prev=back;
    }
}
NODE delete_grade_cdll(NODE head, char delgrade)
{
    NODE back=NULL, cur=head, del=NULL, fwd=NULL;
     if(head==NULL)
        printf("Circular DLL of grades is empty\n");
    else if(head->next==head && head->grade==delgrade)//only one node
    {
        printf("Deleted grade %c\n", head->grade);
        free(head);
        head=NULL;
    }
    else if(head->grade == delgrade)//delete front function
    {
        del = head;
        back = head->prev;

        head = head->next;

        head->prev = back;
        back->next = head;
    }
    else
    {
        while(cur->next != head)
        {
            if(cur->grade == delgrade)
                break;
            back = cur;
            cur = cur->next;
        }
        fwd = cur->next;
        back->next = fwd;
        fwd->prev = back;
        printf("Deleted %c grade\n", cur->grade);
        free(cur);
    }
    return head;
}
