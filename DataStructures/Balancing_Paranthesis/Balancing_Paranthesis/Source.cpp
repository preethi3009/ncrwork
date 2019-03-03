#include<iostream>

using namespace std;

char stack[50];
int top = -1;

//pushing element to the stack
void push(char ele)
{
	stack[++top] = ele;
}

//popping element from the stack;
void pop()
{
	top--;
}

//returns the top element of the stack
char peek()
{
	return stack[top];
}

//checks whether stack top is equal to -1
int isempty()
{
	return(top == -1);
}

//main function
int main()
{
	char s[50],ch;
	int i,stack_size,flag=0;
	
	cout << "enter expression for checking balanced paranthesis" << endl;
	cin >> s;
	
	for (i = 0; i < strlen(s); i++)
	{
		ch = s[i];
		switch (ch)
		{
		case'['://push char to the stcak if it is open paranthesis
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
		if (flag == 1)
			break;
		}
	}

	if (isempty() && flag == 0)
		cout << "balanced" << endl;
	
	else
		cout << "unbalanced" << endl;
	
	return 0;
}