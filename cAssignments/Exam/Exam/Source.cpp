#include<stdio.h>
#include<ctype.h>
int count();
extern int remove();
extern int match(char[]);
extern int replace();
int main()
{
	char ch,word[50];
	printf("choose a option\n(a)count the number of alphabets,digits and special characters\n(b)remove all comments\n(c)match the word and rotate\n(d)replace tabs \n");
	scanf("%c", &ch);
	switch (ch)
	{
	case 'a':count(); break;
	case 'b':remove(); break;
	case 'c':printf("enter a word");
			scanf("%s", word);
			match(word);
			break;
	case 'd':replace(); break;
	default:printf("wrong option");
	}
	return 0;
}
