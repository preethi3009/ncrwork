#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char **arr, str[50], temp[50];
	int n, i, j, len;
	printf("enter no of strings\n");
	scanf("%d", &n);
	arr = (char **)malloc(n * sizeof(char *));
	printf("enter %d strings\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%s",str);
		len = strlen(str) + 1;
		arr[i] = (char *)malloc((len) * sizeof(char));
		strcpy(arr[i], str);
	}
	printf("displaying the strings entered:\n");
	for (i = 0; i < n; i++)
	{
		puts(arr[i]);

	}

	return 0;
}