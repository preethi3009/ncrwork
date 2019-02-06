#include<stdio.h>
#include<ctype.h>
int main()
{
	char text[80],c,i=0,letters=0,digit=0,blank=0,others=0,tab=0;
	printf("enter text");
	scanf("%[^\n]s", text);
	c = text[i];
	while (c != '\0')
	{
		if (isalpha(c))
			letters++;
		else if (isdigit(c))
			digit++;
		else if (c == 9)
			tab++;
		else if (isblank(c))
			blank++;
		else
			others++;
		i++;
		c = text[i];
	}
	printf("letters=%d\ndigits=%d\ntabs=%d\nblank=%d\nothers=%d", letters,digit,tab,blank,others);
	return 0;
}