#include<stdio.h>
#include<math.h>
typedef struct point
{
    float x;
    float y;
}pts;
void read(pts *p)
{
    printf("ENTER X & Y COORDINATES OF POINT\n");
    scanf("%f%f",&p->x,&p->y);
}
void solve(pts *ap, pts *bp)
{
    float s,d;
    d=(float)sqrt((pow((ap->x-bp->x),2))+pow((ap->y-bp->y),2));
    s=(ap->y-bp->y)/(ap->x-bp->x);
    printf("\nDISTANCE BETWEEN 2 POINTS IS %f\n",d);
    printf("SLOPE OF LINE IS %f\n",s);
}
void quadrant(pts *p)
{
    if(p->x==0||p->y==0)
        printf("POINT LIES ON ORIGIN\n");
    else if(p->x>0&&p->y>0)
        printf("POINT LIES ON 1ST QUADRANT\n");
    else if(p->x<0&&p->y>0)
        printf("POINT LIES ON 2ND QUADRANT\n");
    else if(p->x<0&&p->y<0)
        printf("POINT LIES ON 3RD QUADRANT\n");
    else if(p->x>0&&p->y<0)
        printf("POINT LIES ON 4TH QUADRANT\n");
}
void print(pts *p)
{
    printf("\nENTERED X & Y COORDINATES OF POINT ARE\n");
    printf("%0.2f %0.2f",p->x,p->y);
    printf("\n");
}
int main()
{
    pts a,b;
    pts *ap=NULL,*bp=NULL;
    ap=&a;
    bp=&b;
    read(ap);
    read(bp);
    quadrant(ap);
    quadrant(bp);
    print(ap);
    print(bp);
    solve(ap,bp);
}
