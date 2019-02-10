#include<stdio.h>
int main()
{
	int n, r, m = 0;
	printf("enter num of max 8 bits");
	scanf("%d", &n);
	if (n >= 0 && n <= 255)
	{
		while (n != 0)
		{
			r = n % 2;
			if (r == 1)
				m++;
			n = n / 2;
		}
		printf("no of 1s are %d", m);
	}
	else
		printf("entered invalid number");
	return 0;
}