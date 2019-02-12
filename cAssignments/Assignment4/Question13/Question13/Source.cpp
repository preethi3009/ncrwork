#include<stdio.h>
#include<string.h>
int expand(char[], char[]);
int main()
{
	char s1[50], s2[50];
	printf("enter string using shorthand notations\n");
	scanf("%s", s1);
	expand(s1, s2);
	return 0;
}


int expand(char s1[], char s2[])
{
	int i = 0,j=0;
	char c;
	while (s1[i] != '\0')
	{
		if (s1[i]!= '-')
		{
			s2[j] = s1[i];
			j++;
		}
		else
		{
			c = s1[i - 1];
			c++;
			while (c!= s1[i + 1])
			{
				s2[j] = c;
				j++;
				c++;
			}
			s2[j] = c;
		}
		i++;
	}
	s2[j] = '\0';
	printf("the expanded string is:\n");
	puts(s2);
	return 0;
}
