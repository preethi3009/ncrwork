#include <stdio.h>
#include <string.h>

int main()
{
	char s[100],c,a;
	int i=0;
	printf("enter string in lower case\n");
	scanf("%s", s);
	c = s[0];
	while(c!='\0')
	{
		c = s[i];
		a = c - 32;
		if (a == -32)
			break;
		printf("%c", a);
		i++;
	}
	printf("\nenter string in upper case\n");
	scanf("%s", s);
	i = 0;
	c = s[i];
	while (c != '\0')
	{
		a = c + 32;
		if (a == 32)
			break;
		printf("%c", a);
		i++;
		c = s[i];
	}
	return 0;
}