#include<stdio.h>
#include<stdio.h>
int del(char[],char);
int main()
{
	char str[50], c;
	printf("enter string:\n");
	scanf("%[^\n]s", str);
	printf("enter a character\n");
	scanf(" %c",&c);
	del(str, c);
	return 0;
}
int del(char str[],char c)
{
	int i = 0,j=0;
	char str1[50];
	while (str[i] != '\0')
	{
		if (str[i]!= c)
		{
			str1[j] = str[i];
			j++;
		}

		i++;
	}
	str1[j] = '\0';
		printf("%s", str1);
	return 0;
}