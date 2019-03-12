#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


//returns length of the string
int string_length(char *s)
{
	int length = 0;
	for (; *s != '\0'; s++)
		length++;
	return length;
}

//copies one string into another string
char *string_copy(char *source)
{
	char *destination = NULL;
	int length, i = 0;
	length = string_length(source);
	destination = (char *)malloc(sizeof(char)*length);
	for (i = 0; i < length; i++)
		destination[i] = source[i];
	destination[i] = '\0';
	return destination;
}

//concatenates strings
char *string_concat(char *string1, char *string2)
{
	int length1, length2, i, j, k = 0;
	length1 = string_length(string1);
	length2 = string_length(string2);
	char *temp = NULL, *res = NULL;
	temp = (char *)malloc(sizeof(char)*(length1 + length2 + 1));
	for (i = 0; i < length1; i++)
	{
		temp[i] = string1[i];
	}
	for (j = 0; j < length2; j++)
	{
		temp[i] = string2[j];
		i++;
	}

	temp[i] = '\0';
	string1 = string_copy(temp);
	free(temp);
	return string1;
}

//comparing two strings
int string_cmp(char *string1, char *string2)
{
	while (*string1==*string2)
	{
		if (*string1 == '\0')
			return 0;
		string1++;
		string2++;
	}
	if ((*string1 - *string2) > 0)
		return 1;
	else
		return -1;
}

//reversing a string
char *string_rev(char *string)
{
	char *temp;
	int length;
	int i = 0;
	length = string_length(string);
	temp = (char *)malloc(sizeof(char)*length + 1);
	while (length>=0)
	{
		temp[i] = string[length-1];
		i++;
		length--;
	}
	temp[i-1] = '\0';
	string = string_copy(temp);
	free(temp);
	return string;
}
//main function
int main()
{
	int choice, length = 0,res=0;
	char cont;
	char *string1 = NULL;
	char *string2 = NULL;
	char s[100], *result;

	do
	{
		printf("Enter your choice\n");
		printf("1.string length\n2.string copy\n 3.string concatenation\n 4.string compare\n 5.string rev\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			printf("Enter a string\n");
			scanf("%s", s);
			length = string_length(s);
			printf("length of the string %s is %d\n", s, length);
			break;
		}
		case 2:
		{
			printf("Enter a string\n");
			scanf("%s", s);
			result = string_copy(s);
			printf("string copy successful\n");
			printf("source - %s\ndestination - %s\n", s, result);
			break;
		}
		case 3:
		{
			printf("Enter string1\n");
			scanf("%s", s);
			string1 = (char *)malloc(sizeof(char)*(string_length(s) + 1));
			string1 = string_copy(s);
			
			printf("Enter string2\n");
			scanf("%s", s);
			string2 = (char *)malloc(sizeof(char)*(string_length(s) + 1));
			string2 = string_copy(s);
			
			result = string_concat(string1, string2);
			printf("string concatenation successful\n");
			printf("concatenated string is %s\n", result);
			break;
		}
		case 4:
		{
			printf("enter string 1\n");
			scanf("%s", s);
			string1 = (char *)malloc(sizeof(char)*(string_length(s) + 1));
			string1 = string_copy(s);
			printf("Enter string2\n");
			scanf("%s", s);
			string2 = (char *)malloc(sizeof(char)*(string_length(s) + 1));
			string2 = string_copy(s);
			res = string_cmp(string1, string2);
			printf("string comparison successful\n");
			if (res == 0)
				printf("strings are equal\n");
			else if (res == 1)
				printf("string1 is greater than string2\n");
			else
				printf("string2 is greater than string 2\n");

			break;
		}
		case 5:
		{
			printf("enter a string\n");
			scanf("%s", s);
			result = string_rev(s);
			printf("string reverse : %s\n", result);
			break;
		}
		default:
			printf("wrong option\n");
			break;
		}
		printf("Do you want to continue?y/n\n");
		scanf(" %c", &cont);
	} while (cont == 'y' || cont == 'Y');

	return 0;
}