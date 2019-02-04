#include<stdio.h>
void main()
{
	int a[1000],min,max,i=0,n;
	float avg;
	printf("enter numbers. enter 0 or negative numbers to stop\n");
	while(1)
	{	scanf("\n%d",&a[i]);
		if(a[i]<=0)
			break;
		i++;
	}
	n=i;
	min=a[0];
	max=a[0];
	for(i=1;i<n;i++)
	{	if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i];
	}
	printf("entered positive integers are:\n"); 
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
		avg+=a[i];
	}
	avg=avg/n;
	printf("the min num is %d\nthe max num is %d\n",min,max);
	printf(" the avg is %f",avg);
}