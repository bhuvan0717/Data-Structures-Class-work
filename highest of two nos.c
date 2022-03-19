#include<stdio.h>
#include<stdlib.h>
  int add(int*,int*);
  int main()
 {



     int a ,b ,*c,*d;
     c=&a;
     d=&b;
     printf("enter the 2 nos");
     scanf("%d%d",c,d);
     add(c,d);

 }
 int add( int*c,int*d)
 {
     if(*c>*d)
     {
      printf("hence %d is greater than %d",*c,*d);
     }
     else if(*c<*d)
     {
      printf("hence %d is lesser than %d",*c,*d);
     }


 }
