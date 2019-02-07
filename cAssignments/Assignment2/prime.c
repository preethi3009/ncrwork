#include<stdio.h>
int main()
{
	int start, end, i, f, j;
	printf("enter start and end\n");
	scanf("%d%d", &start, &end);
	printf("the prime numbers in the specified range are\n");
	for (i = start; i < end; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				f = 0;
				break;
			}
			else
				f = 1;
		}
		if (f == 1)
			printf("%d\n", i);
	}
		return 0;
}