#include<stdio.h>
int replace()
{
	FILE *fp, *fp1;
	char ch;
	fp = fopen("sample.txt", "r");
	fp1 = fopen("new1.txt", "w");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == 9)
		{
			fputc('\\', fp1);
			fputc('t', fp1);
		}
		else
			fputc(ch, fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp1= fopen("new1.txt", "r");
	while (!feof(fp1))
	{
		ch = fgetc(fp1);
		printf("%c", ch);
	}
	return 0;
}