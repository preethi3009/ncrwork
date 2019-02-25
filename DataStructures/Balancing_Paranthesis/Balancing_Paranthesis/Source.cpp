#include<iostream>
using namespace std;
char stack[50];
int top = -1;

void push(char ele)
{
	stack[++top] = ele;
}
void pop()
{
	top--;
}
char peek()
{
	return stack[top];
}
int isempty()
{
	return(top == -1);
}
int main()
{
	char s[50],ch;
	int i,flag=0;
	cout << "enter expression for checking balanced paranthesis" << endl;
	cin >> s;
	for (i = 0; i < strlen(s); i++)
	{
		ch = s[i];
		switch (ch)
		{
		case'[':
		case'{':
		case '(':
					{
						push(ch);
						break;
					}
		case'}':
		case ']':
		case ')':
					{
						if (!isempty())
						{
							if ((ch == '}'&&peek() == '{') || (ch == ']'&&peek() == '[') || (ch = ')'&&peek() == '('))
							{
								pop();
								break;
							}
						}
						else
						{
							flag = 1;
							break;
						}
					}
		}		if (flag == 1)
			break;
	}
	if (isempty() && flag == 0)
		cout << "balanced" << endl;
	else
		cout << "unbalanced" << endl;
	return 0;
}