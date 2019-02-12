#include<stdio.h>
#include<stdlib.h>

int replace(char *);
int main()
{
	int n;
	char *cat;
	cat=(char *)malloc(20 * sizeof(char));
	printf("enter string\n");
	scanf("%[^\n]s", cat);
	n = replace(cat);
	printf("%d", n);
	return 0;

}
int replace(char *cat)
{
	int i = 0,count=0;
	while (cat[i] != '\0')
	{
		if (cat[i]==32)
		{
			cat[i] = '-';
			i++;
			count++;
		}
			i++;
	}
	puts(cat);
	return count;
}