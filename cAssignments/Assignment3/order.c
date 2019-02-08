#include<stdio.h>
int main()
{
	int arr[50],n,temp, i, j;
	printf("enter size of array");
	scanf("%d", &n);
	printf("enter elements of array");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	j = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
	}
	printf("the modified array is :\n");
	for (i = 0; i < n; i++)
			printf("%d ", arr[i]);
	
	return 0;
}