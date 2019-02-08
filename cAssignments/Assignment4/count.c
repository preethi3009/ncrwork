#include <stdio.h>
#include <string.h>

int main()
{
	char * s[] = { "we will teach you how to" , "Move a mountain" , "Level a building", "Erase the past", "Make a million" };
	int i,j=0,c=0;
	for (i = 0; i < 5; i++)
	{
		while(s[i][j]!='\0')
		{
			if (s[i][j] == 'e'||s[i][j]=='E')
				c++;
			j++;
		}
		j = 0;
	}
	printf("no of e's = %d",c);
	return 0;
}