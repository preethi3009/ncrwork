#include<stdio.h>
int any(char[], char[]);
int loc;
int main()
{
	char s1[50], s2[50];
	printf("enter string 1\n");
	scanf("%[^\n]s", s1);
	printf("enter string 2\n");
	scanf("%s", s2);
	any(s1, s2);
	return 0;
}

int any(char s1[], char s2[])
{
	int i = 0, j,f=0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s2[j] == s1[i])
			{
				printf("%c -> %d\n", s1[i], i);
				break;
			}
			else
				j++;
		}
		i++;
	}
	return 0;
}