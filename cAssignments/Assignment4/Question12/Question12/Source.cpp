#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void deletes2(char*, char*);
int main()
{

	char s1[1000], s2[1000];
	printf("enter string1\n");
	scanf("%s", s1);
	printf("enter string2\n");
	scanf("%s", s2);
	deletes2(s1, s2);
	return 0;
}
void deletes2(char* s1, char* s2)
{
	int count[256] = { 0 };
	int i = 0, j = 0;
	while (s2[i] != '\0')
	{
		count[s2[i]]++;
		i++;
	}
	i = 0;
	while (s1[i] != '\0')
	{
		if (count[s1[i]] == 0)
		{
			s1[j] = s1[i];
			j++;
		}
		i++;
	}
	s1[j] = '\0';
	printf("the output string is %s", s1);
}