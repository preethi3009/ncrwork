#include<stdio.h>
int remove()
{
	FILE *fp1, *fp2;
	char c;
	fp1 = fopen("sample.txt", "r");
	fp2 = fopen("new1.txt", "w");
	while (!feof(fp1))
	{
		c = fgetc(fp1);
		if (c == '/')
		{
			if (c == '/')
			{
				while (c != '\n' && !feof(fp1))
					c = fgetc(fp1);
			}
			else if (c == '*')
			{
				while (c != '*' && !feof(fp1))
					c = fgetc(fp1);
			}
			else
				fputc(c, fp2);
		}
		else
			fputc(c, fp2);			
	}
	fclose(fp1);
	fclose(fp2);
	return 0;

}