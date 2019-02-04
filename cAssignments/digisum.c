#include<stdio.h>
void main()
{
	int num,a,sum=0;
	printf("enter the digit\n");
	scanf("%d",&num);
	while(num>0)
	{	a=num%10;
		sum=sum+a;
		num=num/10;
	}
	printf("the sum of the digits is %d",sum);
}