//#include<iostream>
//using namespace std;
//#define SIZE 100
//
//int add(int, int);
//int sub(int, int);
//double mul(int, int);
//double div1(int, int);
//
//double result = -1;
//
//class Operator_Stack
//{
//	struct stk
//	{
//		int top;
//		char *elements;
//		int size;
//	}stack;
//public:
//	
//	Operator_Stack()
//	{
//		stack.size = SIZE;
//		stack.elements = new char[SIZE];
//		stack.top = -1;
//	}
//	bool isEmpty()
//	{
//		if (stack.top == -1)
//			return true;
//		return false;
//	}
//	bool isFull()
//	{
//		if (stack.top == stack.size - 1)
//			return true;
//		return false;
//	}
//	void Push(char x)
//	{
//		if (isFull())
//			return;
//		else
//			stack.elements[++stack.top] = x;
//	}
//	char Pop()
//	{
//		int x = -999;
//		if (isEmpty())
//		{
//			return x;
//		}
//		x = stack.elements[stack.top--];
//		return x;
//	}
//	char Peek()
//	{
//		int x = -999;
//		if (isEmpty())
//		{
//			return x;
//		}
//		else
//		{
//			x = stack.elements[stack.top];
//			return x;
//		}
//	}
//	~Operator_Stack()
//	{
//		delete (stack.elements);
//	}
//};
//
//int Precedence(char x)
//{
//	if (x == '*' || x == '/')
//		return  3;
//	else if (x == '+' || x == '-')
//		return 2;
//	else
//		return 1;
//}
//
//class Operand_Stack
//{
//	struct stk
//	{
//		int top;
//		int *elements;
//		int size;
//	}stack;
//public:
//	Operand_Stack()
//	{
//		stack.size = SIZE;
//		stack.elements = new int[SIZE];
//		stack.top = -1;
//	}
//	bool isEmpty()
//	{
//		if (stack.top == -1)
//			return true;
//		return false;
//	}
//	bool isFull()
//	{
//		if (stack.top == stack.size - 1)
//		{
//			return true;
//		}
//		return false;
//	}
//	void Push(int x)
//	{
//		if (isFull())
//		{
//			cout << "Stack Full";
//			return;
//		}
//		else
//		{
//			stack.elements[++stack.top] = x;
//		}
//	}
//	int Pop()
//	{
//		int x = -999;
//		if (isEmpty())
//		{
//			return x;
//		}
//		else
//		{
//			x = stack.elements[stack.top--];
//			return x;
//		}
//	}
//	int Peek()
//	{
//		int x = -999;
//		if (stack.top == -1)
//		{
//			return x;
//		}
//		else
//		{
//			x = stack.elements[stack.top];
//			return x;
//		}
//	}
//	~Operand_Stack()
//	{
//		delete (stack.elements);
//	}
//};
//
//int main()
//{
//	char input_string[SIZE];
//	cout << "Enter the string";
//	cin >> input_string;
//	char result[SIZE];
//	Operator_Stack s;
//	int curr = 0;
//	char ch;
//	int k = 0;
//	for (int i = 0; i < strlen(input_string); i++)
//	{
//		ch = input_string[i];
//		if (isdigit(ch) || isalpha(ch))
//		{
//			result[k++] = ch;
//		}
//		else if (ch == '(')
//		{
//			s.Push(ch);
//		}
//		else if (ch == ')')
//		{
//			while (s.Peek() != '(')
//			{
//				result[k++] = s.Pop();
//			}
//			s.Pop();
//		}
//		else if (s.isEmpty())
//		{
//			s.Push(ch);
//		}
//		else if (Precedence(ch) > Precedence(s.Peek()))
//		{ 
//			s.Push(ch);
//		}
//		else
//		{
//			while (Precedence(ch) <= Precedence(s.Peek()))
//			{
//				result[k++] = s.Pop();
//			}
//			s.Push(ch);
//		}
//	}
//	while (!s.isEmpty())
//	{
//		result[k++] = s.Pop();
//	}
//	result[k] = '\0';
//	cout << "String - " << result << endl;
//	Operand_Stack s1;
//	for (int i = 0; i < strlen(result); i++)
//	{
//		char ch;
//		ch = result[i];
//		if (isdigit(ch) && !s1.isFull())
//		{
//			s1.Push(ch - '0');
//		}
//		else
//		{
//			int a = s1.Pop();
//			int b = s1.Pop();
//			switch (ch)
//			{
//			case '+': s1.Push(add(a, b));
//				break;
//			case '-': s1.Push(sub(b, a));
//				break;
//			case '*': s1.Push(mul(b, a));
//				break;
//			case '/': s1.Push(div1(b, a));
//				break;
//			}
//		}
//	}
//	cout << "Result - " << s1.Pop();
//	return 0;
//}