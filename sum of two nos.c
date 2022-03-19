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
     printf("sum=%d",*c+*d);
 }
