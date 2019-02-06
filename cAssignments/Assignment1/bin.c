#include<stdio.h>
int main()
{
	int num,i=0,j,r=0,a[50];
	printf("enter num in the range 0-32");
	scanf("%d", &num);
	if (num > 0 && num < 32)
	{
		while (num > 0)
		{
			r = num % 2;
			a[i] = r;
			i++;
			num = num / 2;
		}
		for (j = i - 1; j >= 0; j--)
		{
			printf("%d", a[j]);
		}
	}

	return 0;

}