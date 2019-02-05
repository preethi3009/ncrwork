#include<stdio.h>
int main()
{
    int num,a,rev=0;
    printf("enter the num");
    scanf("%d",&num);
    while(num>0)
    {
        a=num%10;
        rev=rev*10+a;
        num=num/10;
    }
    printf("the rev of the num is %d",rev);
    return 0;
}
