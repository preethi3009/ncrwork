#include<stdio.h>
int main()
{
	int arr[100], sum, n, i, cal, j,f=0;
	printf("enter no of elements of array\n");
	scanf("%d", &n);
	printf("enter elements of array");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("enter sum\n");
	scanf("%d", &sum);
	for (i = 0; i < n; i++)
	{
		cal = arr[i];
		for (j = i + 1; j < n; j++)
		{
			cal = cal + arr[j];
			if (cal == sum)
			{
				f = 1;
				break;
			}
			if (cal > sum)
				break;
		}
		if (f == 1)
			break;
	}
	printf("sum found between indexes %d and %d", i, j);
	return 0;

}