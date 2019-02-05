#include<stdio.h>
void main()
{
	int num,temp,a,rev=0;
	printf("enter the num\n");
	scanf("%d",&num);
	temp=num;
	while(temp>0)
	{	a=temp%10;
		rev=rev*10+a;
		temp=temp/10;
	}
	if(num==rev)
		printf("it is a palindrome");
	else
		printf("it is not a palindrome");
}
