#include<stdio.h>
int add(int a,int b);
int sub(int a,int b);
void main()
{ int a,b;
printf("enter two numbers");
scanf("%d%d",&a,&b);
printf("add val is %d",add(a,b));
printf("sub val is %d",sub(a,b));
}