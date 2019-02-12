#include<ctype.h>
#include<stdio.h>
int count()
{
	FILE *fp;
	char c;
	int alpha = 0, digit = 0, space = 0, splchar = 0,s=0;
	fp = fopen("sample.txt", "r");
	while (!feof(fp))
	{
		c = fgetc(fp);
		if (isalpha(c))
		{
			alpha++;
		}
		else if (isdigit(c))
		{
			digit++;
		}
		else if (isblank(c))
		{
			space++;
		}
		else if (c != '\n')
			s++;
		else
			splchar++;
	}
	printf("alphabets=%d\ndigits=%d\nspaces=%d\nspecial characters=%d\n", alpha, digit, space, splchar);
	fclose(fp);
	return 0;
}