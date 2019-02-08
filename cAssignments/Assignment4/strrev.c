#include <stdio.h>
#include <string.h>

void reverse(char[], int, int);
int main()
{
	char str[20];
	int len;
	printf("Enter a string to reverse: ");
	scanf("%s", str);
	len= strlen(str);
	reverse(str, 0, len-1);
	printf("The string after reversing is: %s\n", str);
	return 0;
}

void reverse(char str[], int i, int size)
{
	char temp;
	temp = str[i];
	str[i] = str[size - i];
	str[size - i] = temp;
	if (i == size / 2)
	{
		return;
	}
	reverse(str, i + 1, size);
}