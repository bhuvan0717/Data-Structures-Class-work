#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 25

struct stack
{
    char name[SIZE];
    int top;
};
typedef struct stack STACK;

void push(STACK *s, char data);
char pop(STACK *s);
void reversestring(STACK *s);

int main()
{
    STACK s;
    s.top = -1;
    reversestring(&s);
    return 0;
}

void push(STACK *s, char data)
{
    if(s->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top ++;
        s->name[s->top] = data;
    }
}

char pop(STACK *s)
{
    char data;
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        data = s->name[s->top];
        s->top--;
        return data;
    }
}

void reversestring(STACK *s)
{
    int x=0;
    char str1[25], str2[25];
    printf("enter the string\n");
    scanf("%s",str1);
    while(str1[x] != 0)
    {
        push(s, str1[x]);
        x++;
    }
    x=0;
    while(s->top != -1)
    {
        str2[x] = pop(s);
        printf("%c",str2[x]);
        x++;

    }
    printf("\n");
    str2[x] = '\0';
    if(strcmp(str1, str2)==0)
        printf("%s is a palindrome \n", str1);
    else
        printf("%s is not a palindrome \n", str1);

        printf("number of elements= %d",x);
}
