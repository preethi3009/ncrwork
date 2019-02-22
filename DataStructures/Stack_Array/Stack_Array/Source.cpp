#include<iostream>
using namespace std;
struct stack
{
	int *stack_arr;
	int top;
	int size;
};
class _stack_
{
	struct stack stack_struct_ins;
public:
	_stack_();
	void push(int);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void setSize(int);
	void display();
	~_stack_();
};
_stack_::_stack_()
{
	stack_struct_ins.top = -1;
	stack_struct_ins.stack_arr = NULL;
	stack_struct_ins.size = 0;
}
void _stack_::setSize(int n)
{
	stack_struct_ins.size = n;
	stack_struct_ins.stack_arr = new int[n];
}
bool _stack_::isFull()
{
	return (stack_struct_ins.top == (stack_struct_ins.size - 1));
}
bool _stack_::isEmpty()
{
	return (stack_struct_ins.top == -1);
}
void _stack_::push(int ele)
{
	if (!isFull())
		stack_struct_ins.stack_arr[++stack_struct_ins.top] = ele;
	else
		cout << "stack is full" << endl;
}
int _stack_::pop()
{
	int x = -999;
	if (!isEmpty())
		x = stack_struct_ins.stack_arr[stack_struct_ins.top--];
	else
		cout << "stack is empty"<<endl;
	return x;
}
int _stack_::peek()
{
	int x = -999;
	if (!isEmpty())
		x = stack_struct_ins.stack_arr[stack_struct_ins.top];
	else
		cout << "empty" << endl;
	return x;
}
void _stack_::display()
{
	for (int i = 0; i <= stack_struct_ins.top; i++)
	{
		cout << stack_struct_ins.stack_arr[i] << endl;
	}
}
_stack_::~_stack_()
{
	delete stack_struct_ins.stack_arr;
}

int main()
{
	_stack_ stack_obj;
	int i,ele,res;
	char ch;
	do
	{
		cout << "chose a stack operation" << endl;
		cout << "1.setSize 2.push 3.pop 4.peek 5.display" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			cout << "enter the size of the stack" << endl;
			cin >> ele;
			stack_obj.setSize(ele);
			break;
		}
		case 2:
		{
			cout << "enter ele to push" << endl;
			cin >> ele;
			stack_obj.push(ele);
			break;
		}
		case 3:
		{
			res = stack_obj.pop();
			if(res!=-999)
			cout << "popped ele is " << res << endl;
			break;
		}
		case 4:
		{
			res = stack_obj.peek();
			if(res!=-999)
			cout << "top of the stack is " << res << endl;
			break;
		}
		case 5:
		{
			cout << "displaying stack elements" << endl;
			stack_obj.display();
			break;
		}
		default:cout << "wrong operation" << endl;
			break;
		}
		cout << "do you want to continue? y/n " << endl;
		cin >> ch;
	} while (ch == 'y');
	return 0;
}