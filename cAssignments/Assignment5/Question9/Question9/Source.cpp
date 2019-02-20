#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	FILE *fp;
	int i = 0;
	char str[50],ch;
	fp = fopen("Text.txt", "w");
	printf("enter the text\n");
	scanf("%[^\n]s", str);
	while (i <= strlen(str))
	{
		ch = str[i];
		if (isupper(ch))
		{
			ch = ch + 32;
			fputc(ch, fp);
		}
		else if (islower(ch))
		{
			ch = ch - 32;
			fputc(ch, fp);
		}
		else
			fputc(ch, fp);

		i++;
	}
	fclose(fp);
	return 0;
}