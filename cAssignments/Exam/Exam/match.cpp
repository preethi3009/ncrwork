#include<stdio.h>
#include<string.h>
int match(char str[])
{
	FILE *fp,*fp1;
	char ch,rv;
	int len;
	len = strlen(str);
	int i = 0;
	fp = fopen("sample.txt", "r");
	fp1 = fopen("new1.txt", "w");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		i = 0;
		if (ch == str[i])
		{
			while (ch == str[i] && str[i] != '\0')
			{
				ch = fgetc(fp);
				i++;
			}
			if (str[i] == '\0')
			{
				while (len >= 0)
				{
					fputc(str[len], fp1);
					len--;
				}
			}
		
		}
		else
			fputc(ch, fp1);

	}
	fclose(fp);
	fclose(fp1);
	fp1 = fopen("new1.txt","r");
	while (!feof(fp1))
	{
		ch = fgetc(fp1);
		printf("%c", ch);
	}
	fclose(fp1);
	fclose(fp);
	return 0;

}