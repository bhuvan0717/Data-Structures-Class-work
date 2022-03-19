#include<stdio.h>
#include<stdlib.h>
  void area(int*);
  void main()
 {

     int r ,*c;
     c=&r;
     printf("enter the radius");
     scanf("%d",&r);
     area(c);

 }
 void area( int*c)
 {
     float x=3.142,w;
     w= x * (*c) * (*c);
     printf("area=%f",w);
 }

