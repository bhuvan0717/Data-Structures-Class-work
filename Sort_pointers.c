#include <stdio.h>
#include <stdlib.h>

void sort(int *ptr, int n);
void read(int *ptr, int n);
void display(int *ptr, int n);

void main()
{
	int n,*ptr;
	printf("ENTER NUMBER OF ELEMNTS IN ARRAY: ");
	scanf("%d",&n);
	ptr=(int *) malloc(2*n);
	if(ptr==NULL)
	{
		printf("\nMEMORY ALLOCATION UNSUCCESSFUL");
		exit(0);
	}
	read(ptr,n);
	printf("\nENTERED ELEMENTS ARE\t");
	display(ptr,n);
	sort(ptr,n);
	printf("\nSORTED ELEMENTS ARE\t");
	display(ptr,n);
}

void read(int *ptr, int n)
{
    for(int i=0;i<n;i++)
	{
		printf("ENTER ARRAY ELEMENT %d: ",i+1);
		scanf("%d",ptr+i);
	}
}

void display(int *ptr, int n)
{
    for(int i=0;i<n;i++)
	{
		printf("%d\t",*(ptr+i));
	}
}

void sort(int *ptr, int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (*(ptr+j)<*(ptr+i))
            {
                temp=*(ptr+i);
                *(ptr+i)=*(ptr+j);
                *(ptr+j)=temp;
            }
        }
    }
}
