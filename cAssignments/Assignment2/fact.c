#include<stdio.h>
int fact(int);
int main()
{
    int num,res;
    printf("enter num");
    scanf("%d",&num);
    res=fact(num);
    printf("the factorial of the num is %d",res);
    return 0;
}
int fact(int n)
{
    if(n==0)
    return 1;
    else
    return n*fact(n-1);
}
