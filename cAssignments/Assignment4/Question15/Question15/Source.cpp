#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *strRev(char *);
char *strCpy(char*, char*);
char *strCat(char *, char *);
int strCmp(char *, char *);
int len1, len2;
int main()
{
	char str1[50],str2[50];
	int n;
	printf("enter string1:\n");
	scanf("%s", str1);
	printf("enter string2:\n");
	scanf("%s", str2);
	len1 = strlen(str1) ;
	len2 = strlen(str2) ;
	char *s1 = (char*)malloc((len1+1) * sizeof(char));
	char *s2 = (char*)malloc((len2+1) * sizeof(char));
	char *s;
	s = strRev(s1);
	printf("reverse of string1: %s\n", s);
	s = strCpy(s, s1);
	printf("string copy: %s\n", s);
	s = strCat(s1,s2);
	printf("string conatenation: %s\n", s1);
	n = strCmp(s1, s2);
	printf("string compare: %d\n", n); 

	return 0;
}
char *strRev(char *s)
{
	char temp;
	char* p1 = s;
	char* p2 = s;
	for (p1 = s, p2 = (s + (len1 - 1)); p1 < p2; p1++, p2++)
	{
		//temp = *p1;
		//*p1 = *p2;
		//*p2 = temp;
	}
	return s;
}
char *strCpy(char *p1, char *p2)
{
	while ((*p1++ = *p2++) != '\0');
	return p1;
}
char *strCat(char *p1, char *p2)
{
	p1 = (char*)realloc(p1, len1 + len2 + 1);
	char *q1 = p1;
	char *q2 = p2;
	while (*q1 != '\0')
		q1++;
	while ((*q1++ = *q2++) != '\0');
	return p1;
}
int strCmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	if ((*s1 - *s2) > 0)
		return 1;
	else
		return -1;
}