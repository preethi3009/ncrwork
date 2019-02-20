#include<stdio.h>
int main()
{
	FILE *fp;
	char ch;
	fp = fopen("sample.txt", "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	return 0;
}