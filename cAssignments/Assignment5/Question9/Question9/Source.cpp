#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	FILE *fp;
	int i = 0,p;
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
	fp = fopen("Text.txt", "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	p=ftell(fp);
	printf("current position - %d\n", p);
	fseek(fp, 7, SEEK_SET);
	p = ftell(fp);
	printf("current position after fseek - %d\n", p);
	printf("printing file contents from current position\n");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	fclose(fp);
	return 0;
}