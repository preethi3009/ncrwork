#include<stdio.h>
#include<math.h>
void main()
{
	int j,num,a[100],i=0,q,sum=0;
	printf("enter num\n");
	scanf("%d",&num);
	q=num;
	while(num>0)
	{	a[i]=num%10;
		i++;
		num=num/10;
	}
	for(j=0;j<i;j++)
 		sum=sum+pow(a[j],i);
	if(sum==q)
		printf("\nit is an amstrong number");
	else
		printf("\nit is not an amstrong number");
}

