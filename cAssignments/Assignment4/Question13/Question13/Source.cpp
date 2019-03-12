//13.Write a function expand(s1, s2) which expands shorthand notations of s1
//like a - d into abcd and 0 - 9 to 0123456789 in s2.For example if the string
//in s1 is 0123a - e1 - 4 then s1 is expanded in s2 to 0123abcde1234

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int expandShorthand(char[], char[]);//function for expanding the shorthand notation

int main()
{
	char cShorthandArray[50], cExpandedArray[50], iReturn;

	printf("enter string using shorthand notations\n");//input from user
	scanf("%s", cShorthandArray);

	iReturn = expandShorthand(cShorthandArray, cExpandedArray);

	if (-1 == iReturn)
		printf("Invalid input\n");

	return 0;
}


int expandShorthand(char cShorthandArray[], char cExpandedArray[])
{
	int iShorthandArrayIndex = 0, iExpandedArrayIndex = 0;
	char cTemp;

	if (cShorthandArray[iShorthandArrayIndex] == '-')
		return -1;

	while (cShorthandArray[iShorthandArrayIndex] != '\0')//looping through the shorthand array
	{
		if (!isalnum(cShorthandArray[iShorthandArrayIndex])&&cShorthandArray[iShorthandArrayIndex]!='-')//checking for valid input
			return -1;

		if (cShorthandArray[iShorthandArrayIndex] != '-')
		{
			cExpandedArray[iExpandedArrayIndex] = cShorthandArray[iShorthandArrayIndex];
			iExpandedArrayIndex++;
		}

		else if (cShorthandArray[iShorthandArrayIndex] == '-' && cShorthandArray[iShorthandArrayIndex + 1] != '\0')
		{
			cTemp = cShorthandArray[iShorthandArrayIndex - 1];
			cTemp++;
			if ((cShorthandArray[iShorthandArrayIndex + 1]) <= (cShorthandArray[iShorthandArrayIndex-1]))
				return -1;
			while (cTemp != cShorthandArray[iShorthandArrayIndex + 1])
			{
				cExpandedArray[iExpandedArrayIndex] = cTemp;
				iExpandedArrayIndex++;
				cTemp++;
			}
			cExpandedArray[iExpandedArrayIndex] = cTemp;
		}

		else
			return -1;

		iShorthandArrayIndex++;
	}
	cExpandedArray[iExpandedArrayIndex] = '\0';//terminating the expanded array with null character

	printf("the expanded string is:\n");
	puts(cExpandedArray);//printing the expanded array

	return 0;
}
